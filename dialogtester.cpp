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

    ui->listView->get_model()->_storage->Load();

    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->listView->show_big_items(true);

    ui->listView->select_last_row();

    //ui->listView->scrollDown();

}

DialogTester::~DialogTester()
{
    delete ui;
}

void DialogTester::on_pushButton_clicked(bool checked)
{
    EntryFileInfo* efi = ui->listView->get_selection();

    TSCore::I().workingMonth = efi->date.month();
    TSCore::I().workingYear = efi->date.year();
    TSCore::I().needReload = true;

    this->close();
}
