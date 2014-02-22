#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QListView>
#include <QCompleter>
#include <QDebug>
#include <QDesktopServices>
#include "GUI/entry/model/entrylistmodel.h"

#include "Common/style.h"
#include "Common/tscore.h"

#include "GUI/entry/delegate/entryitemdelegate.h"
#include "dialogtester.h"
#include "exportdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/images/Earth-icon.png"));
    ui->actionExit->setIcon(QIcon(":/system/power_off.png"));

    ui->actionShow_spectrum->setChecked(true);

    connect(ui->listView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(on_listView_clicked(const QModelIndex&)));
    connect(ui->listView, SIGNAL(sig_sel_changed(const QModelIndex&)),this, SLOT(on_listView_clicked(const QModelIndex&)));

    connect(ui->descriptionTextEdit, SIGNAL(textChanged()), this, SLOT(on_descriptionChanged()));
    connect(ui->titleLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_titleChanged(QString)));
    connect(ui->fromLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_fromChanged(QString)));
    connect(ui->toLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_toChanged(QString)));
    connect(ui->dateLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_dateChanged(QString)));
    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(on_currentTextChanged(QString)));
    connect(ui->filterLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_filteredTextChnged(QString)));

    connect(this, SIGNAL(destroyed()), this, SLOT(on_Savetimeout()));

    // set up style
    //Style::get_style(true);
    QString style = Style::get_style(true);
    this->setStyleSheet(style);

    Refresh("Today");

    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->listView->show_big_items(true);
    ui->listView->select_row(0);

    HandleFilters();

    ui->comboBox->setFocusPolicy(Qt::NoFocus);

    manager = new TSManager();

    //set up filter to today
    int todayIndex = ui->comboBox->findText("Today");
    ui->comboBox->setCurrentIndex(todayIndex);

    ui->descriptionTextEdit->setStyleSheet(Style::set_textEdit_style());
    ui->descriptionTextEdit->setAcceptRichText(true);
    //ui->titleLineEdit->setStyleSheet(Style::set_textEdit_style());

    timer = new QTimer(this) ;
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
    timer->setInterval(2000);
    timer->start();

    timerSave = new QTimer(this) ;
    connect(timerSave, SIGNAL(timeout()), this, SLOT(on_Savetimeout()));
    timerSave->setInterval(60000); // co 60 s
    timerSave->start();

    this->setMouseTracking(true);


    PersistentStorage_XML* storage = &TSCore::I().entriesStorage;
    QList<float> list = storage->GetSpectrum();
    ui->spectrum->set_spectrum(list);

    ui->spectrum->setMinimumWidth(ui->spectrum->height()*1.618);
    ui->spectrum->resize(ui->spectrum->height()*1.618,ui->spectrum->height());

    this->resize(this->height()*1.618, this->height());
    ui->descriptionTextEdit->setMouseTracking(true);

    ui->urlLabel->setText("");
    ui->urlLabel->setMaximumHeight(24);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;

    // delete filters
    delete ft;
    //delete fv;
    //delete fiv;
    delete fy;
    delete ftw;
    delete fa;
}

void MainWindow::HandleFilters()
{
    ft = new Filter_Today();
//    fv = new Filter_Valid();
//    fiv = new Filter_Invalid();
    fy = new Filter_Yesterday();
    ftw = new Filter_Thisweek();
    fa = new Filter_All();

    filters.insert(ft->name,ft);
    //filters.insert(fv->name,fv);
//    filters.insert(fiv->name,fiv);
    filters.insert(fy->name,fy);
    filters.insert(ftw->name,ftw);
    filters.insert(fa->name,fa);

    foreach (FilterBase* f, filters)
    {
        ui->comboBox->addItem(f->name);
    }
}

void MainWindow::on_timeout()
{
    FileInfoStorage* s = &TSCore::I().fiStorage;

    if (!s->isLoaded || s->needRefresh)
    {
        ui->statusbar->showMessage("Loading history", 2000);
        s->Load(true);
        ui->statusbar->showMessage("History loaded", 2000);


        QCompleter *completer = new QCompleter(TSCore::I().fiStorage.titles, this);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        ui->titleLineEdit->setCompleter(completer);

        timer->stop();
    }
}

void MainWindow::on_Savetimeout()
{
    ui->statusbar->showMessage("Saving...", 1000);
    ui->listView->UpdateAndSave();
}

#define DO_NOT_SAVE_ONCHANGE(b) _do_not_save_onchange = b
void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    QVariant q = index.model();
    //QString qs = q.toString();

    Entry *e = ui->listView->get_selection();

    if (e != NULL)
    {
        DO_NOT_SAVE_ONCHANGE(true);
        ui->dateLineEdit->setText(e->date.toString("dd.MM.yyyy"));
        ui->fromLineEdit->setText(e->from.toString("hh:mm"));
        ui->toLineEdit->setText(e->to.toString("hh:mm"));
        ui->titleLineEdit->setText(e->title);
        ui->descriptionTextEdit->setText(e->description.replace("\n", "<br/>"));
        DO_NOT_SAVE_ONCHANGE(false);
    }
}

void MainWindow::on_titleChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();
    if (e!=NULL)
        e->title = changedText;

    UpdateStatusBar();
}

void MainWindow::on_toChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();
    if (e!=NULL)
        e->to = Helper::ConstructTime(changedText);

    UpdateStatusBar();
}

void MainWindow::on_fromChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();
    if (e!=NULL)
        e->from = Helper::ConstructTime(changedText);

    UpdateStatusBar();
}

void MainWindow::on_dateChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();

    if (e!=NULL)
        e->date = Helper::ConstructDate(changedText);

    UpdateStatusBar();
}

void MainWindow::on_descriptionChanged()
{
    Entry *e = ui->listView->get_selection();
    if (e!=NULL)
    {
        e->description = ui->descriptionTextEdit->toPlainText();

        if (e->description.contains("http"))
        {
            QString urls = e->GetUrlsAsTitles();
            ui->urlLabel->setText("<img src=':images/Earth-icon.png' width='24' height='24' />");
            ui->urlLabel->setToolTip(urls);
        }
        else
        {
            ui->urlLabel->setText("");
        }

        QStringList tags = e->GetTags();
        foreach (QString s, tags) {
            //handle tags
            Tag* t = TSCore::I().GetTag(s);
            if (t==NULL)
            {
                Tag* t = new Tag();
                t->code = s;
                TSCore::I().entriesStorage.tags.append(t);
            }
        }
    }

    UpdateStatusBar();
}

void MainWindow::on_currentTextChanged(QString newText)
{
    FilterBase* f = filters[newText];
    if (f!=NULL)
    {
        f->highlightTodayEntries = ui->actionHighlight_today_entries->isChecked();
        ui->listView->ApplyFilter(f);
    }
    else
    {
        qDebug() << "unknown filter: " << newText;
    }
}

void MainWindow::on_actionSmall_items_triggered(bool checked)
{
    ui->listView->show_big_items(!checked);
    ui->listView->update();
}

void MainWindow::on_actionSelect_different_month_triggered()
{
    DialogTester tester(this);
    tester.exec();

    Refresh("All");
}

void MainWindow::UpdateStatusBar()
{
    if (!_do_not_save_onchange)
        on_Savetimeout();

    // analyze filtered items.
    EntryFileInfo efi;
    EntriesAnalyzer an = EntriesAnalyzer(&ui->listView->get_model()->_storage->filteredEntries, &efi);
    an.Analyze();

    QString message;
    if (efi.workedHours < 24)
    {
        message = QString("Worked hours: %1")
                .arg(Helper::GetSecsAshhmm(efi.workedHours*60*60));

    }
    else
    {
        message = QString("Worked hours: %1h")
                .arg(efi.workedHours);

    }

    ui->statusbar->showMessage(message);

    //update values on spectrum :)
    RefreshSpectrum();
}

void MainWindow::on_actionGo_back_to_current_month_triggered()
{
    TSCore::I().MoveToPresent();
    Refresh("Today");
}

void MainWindow::on_actionNext_month_triggered()
{
    TSCore::I().MoveForward();
    Refresh("All");
}

void MainWindow::on_actionPrevious_month_triggered()
{
    TSCore::I().MoveBackward();
    Refresh("All");
}

void MainWindow::Refresh(QString finalFilter)
{
    PersistentStorage_XML* storage = ui->listView->get_model()->_storage;
    storage->Load();

    RefreshSpectrum();

    int todayIndex = ui->comboBox->findText("Valid");
    ui->comboBox->setCurrentIndex(todayIndex);

    todayIndex = ui->comboBox->findText(finalFilter);
    ui->comboBox->setCurrentIndex(todayIndex);

    QString qsWindowTitle = QString("%1 :: %2, %3")
            .arg("Timesheet")
            .arg(TSCore::I().workingMonth)
            .arg(TSCore::I().workingYear);

    this->setWindowTitle(qsWindowTitle);
    UpdateStatusBar();
}

void MainWindow::RefreshSpectrum()
{
    PersistentStorage_XML* storage = &TSCore::I().entriesStorage;

    QList<float> list = storage->GetSpectrum();
    ui->spectrum->set_spectrum(list);
    ui->spectrum->psl_style_update();
}

void MainWindow::on_actionCreate_desktop_file_triggered()
{
    QDir dir;

    QString qsExe = dir.absolutePath()+"/Timesheet";
    QString qsIcon = dir.absolutePath()+"/Earth-icon.png";

    QString str = QString()+
                "[Desktop Entry]\r\n"+
                "Name=Timesheet v %4\r\n"+
                "Comment=Application for measuring work time\r\n"+
                "Exec=%1\r\n"+
                "Icon=%2\r\n"+
                "Path=%3\r\n"+
                "Terminal=false\r\n"+
                "Type=Application\r\n"+
                "Categories=Game;\r\n\r\n"+

                "Actions=Test\r\n"+

                "[Desktop Action Test]\r\n"+
                "Name=Test action\r\n"+
                "Exec=audacious -r\r\n"+
                "OnlyShowIn=Unity;\r\n";

    str = str.arg(qsExe).arg(qsIcon).arg(dir.absolutePath()).arg(TSCore::I().GetVersion());

    QString home = dir.homePath();
    QString desktopPath  = QStandardPaths::displayName( QStandardPaths::DesktopLocation );

    QString pathToDesktop = QString()+
            home+"/"+desktopPath+"/timesheet.desktop";

    Helper::write_file(pathToDesktop, str);

    //set as execultable
    system(qPrintable("chmod +x "+pathToDesktop));

    //delete myProcess;
}

void MainWindow::on_filteredTextChnged(QString changedText)
{
    ui->listView->ApplySearch(changedText);
}


void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionShow_spectrum_triggered(bool checked)
{
    ui->spectrum->setVisible(checked);
}

void MainWindow::on_actionExport_triggered()
{
    ExportDialog export(this);
    export.exec();
}
