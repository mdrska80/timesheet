#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QListView>
#include <QCompleter>
#include <QDebug>
#include "GUI/entry/model/entrylistmodel.h"

#include "Common/style.h"
#include "Common/tscore.h"

#include "GUI/entry/delegate/entryitemdelegate.h"
#include "dialogtester.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/images/Earth-icon.png"));
    ui->actionExit->setIcon(QIcon(":/system/power_off.png"));


    connect(ui->listView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(on_listView_clicked(const QModelIndex&)));
    connect(ui->listView, SIGNAL(sig_sel_changed(const QModelIndex&)),this, SLOT(on_listView_clicked(const QModelIndex&)));

    connect(ui->descriptionTextEdit, SIGNAL(textChanged()), this, SLOT(on_descriptionChanged()));
    connect(ui->titleLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_titleChanged(QString)));
    connect(ui->fromLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_fromChanged(QString)));
    connect(ui->toLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_toChanged(QString)));
    connect(ui->dateLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_dateChanged(QString)));
    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(on_currentTextChanged(QString)));

    // set up style
    //Style::get_style(true);
    QString style = Style::get_style(true);
    this->setStyleSheet(style);

    Refresh("Today");

    //ReloadModel();

    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->listView->show_big_items(true);
    ui->listView->select_row(0);

    QFont font;
    font.setFamily(QString::fromUtf8("DejaVu Sans"));

    ui->comboBox->addItem("Valid");
    ui->comboBox->addItem("InValid");
    ui->comboBox->addItem("Today");
    ui->comboBox->addItem("Yesterday");
    ui->comboBox->addItem("This week");
    ui->comboBox->addItem("All");
    ui->comboBox->setFont(font);

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

}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}

void MainWindow::on_timeout()
{
    FileInfoStorage* s = &TSCore::I().fiStorage;

    if (!s->isLoaded || s->needRefresh)
    {
        ui->statusbar->showMessage("Loading history", 2000);
        s->Load();
        ui->statusbar->showMessage("History loaded", 2000);
    }

    QCompleter *completer = new QCompleter(TSCore::I().fiStorage.titles, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->titleLineEdit->setCompleter(completer);

    timer->stop();

}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    QVariant q = index.model();
    //QString qs = q.toString();

    Entry *e = ui->listView->get_selection();

    if (e != NULL)
    {
        ui->dateLineEdit->setText(e->date.toString("dd.MM.yyyy"));
        ui->fromLineEdit->setText(e->from.toString("hh:mm"));
        ui->toLineEdit->setText(e->to.toString("hh:mm"));
        ui->titleLineEdit->setText(e->title);
        ui->descriptionTextEdit->setText(e->description);
    }
}

void MainWindow::on_titleChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();
    if (e!=NULL)
    {
        e->title = changedText;
        ui->listView->UpdateAndSave();
    }

    UpdateStatusBar();
}

void MainWindow::on_toChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();
    if (e!=NULL)
    {
        e->to = Helper::ConstructTime(changedText);

        ui->listView->UpdateAndSave();
    }

    UpdateStatusBar();
}

void MainWindow::on_fromChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();
    if (e!=NULL)
    {
        e->from = Helper::ConstructTime(changedText);

        ui->listView->UpdateAndSave();
    }

    UpdateStatusBar();
}

void MainWindow::on_dateChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();

    if (e!=NULL)
    {
        e->date = Helper::ConstructDate(changedText);  //QDate::fromString(changedText, "dd.MM.yyyy");
        ui->listView->UpdateAndSave();
        //ui->listView->get_model()->ApplyFilter();
    }

    UpdateStatusBar();
}

void MainWindow::on_descriptionChanged()
{
    Entry *e = ui->listView->get_selection();
    if (e!=NULL)
    {
        e->description = ui->descriptionTextEdit->toPlainText();
        ui->listView->UpdateAndSave();
    }

    UpdateStatusBar();
}

void MainWindow::on_currentTextChanged(QString newText)
{
    if (newText == "Valid")
        ui->listView->get_model()->ft = FilterType_Valid;

    if (newText == "InValid")
        ui->listView->get_model()->ft = FilterType_InValid;

    if (newText == "Today")
        ui->listView->get_model()->ft = FilterType_Today;

    if (newText == "Yesterday")
        ui->listView->get_model()->ft = FilterType_Yesterday;

    if (newText == "All")
        ui->listView->get_model()->ft = FilterType_All;

    if (newText == "This week")
        ui->listView->get_model()->ft = FilterType_ThisWeek;


//    qDebug() << "Filter type:" << ui->listView->get_model()->ft;

    ui->listView->get_model()->ApplyFilter(ui->actionHighlight_today_entries->isChecked());
    ui->listView->update();

    UpdateStatusBar();
}

void MainWindow::on_actionSmall_items_triggered(bool checked)
{
    ui->listView->show_big_items(!checked);
    ui->listView->update();
}

void MainWindow::on_actionHighlight_today_entries_triggered(bool checked)
{
    ui->listView->get_model()->ApplyFilter(checked);
    ui->listView->update();
}

void MainWindow::on_actionSelect_different_month_triggered()
{
    DialogTester tester(this);
    tester.exec();

    if (TSCore::I().needReload)
    {
        Refresh("All");
    }

    update();
}

void MainWindow::UpdateStatusBar()
{
    // analyze filtered items.
    EntryFileInfo efi;
    EntriesAnalyzer an = EntriesAnalyzer(&ui->listView->get_model()->_storage->filteredEntries, &efi);
    an.Analyze();

    QString message;
    if (efi.workedHours < 24)
    {
        message = QString("Worked hours: %1")
                .arg(Helper::NumberToTime(efi.workedHours).toString("hh:mm"));

    }
    else
    {
        message = QString("Worked hours: %1h")
                .arg(efi.workedHours);

    }

    ui->statusbar->showMessage(message);
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
    ui->listView->get_model()->_storage->Load();

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
