#include "dialogtester.h"
#include "ui_dialogtester.h"
#include "Common/style.h"

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
    ui->listView->select_row(0);

}

DialogTester::~DialogTester()
{
    delete ui;
}
