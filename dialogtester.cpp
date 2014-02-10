#include "dialogtester.h"
#include "ui_dialogtester.h"
#include "Common/style.h"
#include "Common/tscore.h"

DialogTester::DialogTester(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTester)
{
    ui->setupUi(this);

    // set up style
    //Style::get_style(true);
    QString style = Style::get_style(true);
    this->setStyleSheet(style);

//    ui->listView->get_model()->_storage->Load();

    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->listView->show_big_items(true);

    ui->listView->select_last_row(5);

    connect(ui->filterLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_filteredTextChnged(QString)));
//    connect(this, SIGNAL(destroyed()), this, SLOT(on_pushButton_clicked()));
    //ui->levels->psl_stop();
    ui->tag->set_tag("testovaci tag", Qt::blue);
    //ui->levels->set_level(0.1f,0.1f);
//    ui->levels->psl_stop();
    //ui->listView->scrollDown();

}

DialogTester::~DialogTester()
{
    delete ui;
}

void DialogTester::on_pushButton_clicked()
{
    EntryFileInfo* efi = ui->listView->get_selection();
    TSCore::I().needReload = true;

    if (efi!=NULL)
    {
        TSCore::I().workingMonth = efi->date.month();
        TSCore::I().workingYear = efi->date.year();
    }
    else
    {
        TSCore::I().MoveToPresent();
    }

    this->close();
}

void DialogTester::on_filteredTextChnged(QString changedText)
{
    ui->listView->ApplyFilter(changedText);
    // 5 je max
    // -45 je 0
    //ui->levels->set_level(100,0);
    //ui->levels->psl_stop();
}

void DialogTester::closeEvent(QCloseEvent *event)
{
    ui->listView->select_last_row(5);
    //int a =9;
    //on_pushButton_clicked();
}

