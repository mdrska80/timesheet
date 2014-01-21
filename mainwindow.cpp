#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QListView>

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


    connect(ui->listView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(on_listView_clicked(const QModelIndex&)));
    connect(ui->listView, SIGNAL(sig_sel_changed(const QModelIndex&)),this, SLOT(on_listView_clicked(const QModelIndex&)));

    connect(ui->descriptionTextEdit, SIGNAL(textChanged()), this, SLOT(on_descriptionChanged()));
    connect(ui->titleTextEdit, SIGNAL(textChanged()), this, SLOT(on_titleChanged()));
    connect(ui->fromLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_fromChanged(QString)));
    connect(ui->toLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_toChanged(QString)));
    connect(ui->dateLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_dateChanged(QString)));
    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(on_currentTextChanged(QString)));

    // set up style
    //Style::get_style(true);
    QString style = Style::get_style(true);
    this->setStyleSheet(style);

    ReloadModel();

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
    ui->titleTextEdit->setStyleSheet(Style::set_textEdit_style());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}

void MainWindow::ReloadModel()
{
    ui->listView->get_model()->_storage->Load();

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
        ui->titleTextEdit->setText(e->title);
        ui->descriptionTextEdit->setText(e->description);
    }
}

void MainWindow::on_titleChanged()
{
    Entry *e = ui->listView->get_selection();
    if (e!=NULL)
    {
        e->title = ui->titleTextEdit->toPlainText();
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
        ReloadModel();

        int todayIndex = ui->comboBox->findText("Valid");
        ui->comboBox->setCurrentIndex(todayIndex);

        todayIndex = ui->comboBox->findText("All");
        ui->comboBox->setCurrentIndex(todayIndex);
    }

    update();
}

void MainWindow::UpdateStatusBar()
{
    // analyze filtered items.
    EntryFileInfo efi;
    EntriesAnalyzer an = EntriesAnalyzer(&ui->listView->get_model()->_storage->filteredEntries, &efi);
    an.Analyze();

    QString message = QString("Worked hours: %1")
            .arg(Helper::NumberToTime(efi.workedHours).toString());

    ui->statusbar->showMessage(message);
}

void MainWindow::on_actionGo_back_to_current_month_triggered()
{
    TSCore::I().workingMonth = QDate::currentDate().month();
    TSCore::I().workingYear = QDate::currentDate().year();

    ReloadModel();

    int todayIndex = ui->comboBox->findText("Valid");
    ui->comboBox->setCurrentIndex(todayIndex);

    todayIndex = ui->comboBox->findText("Today");
    ui->comboBox->setCurrentIndex(todayIndex);

}
