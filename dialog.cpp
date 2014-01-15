#include "dialog.h"
#include "ui_dialog.h"

#include <QStandardItemModel>
#include <QListView>

#include <QDebug>
#include "GUI/entry/model/entrylistmodel.h"

#include "Common/style.h"

#include "GUI/entry/delegate/entryitemdelegate.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


    connect(ui->listView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(on_listView_clicked(const QModelIndex&)));

    connect(ui->descriptionTextEdit, SIGNAL(textChanged()), this, SLOT(on_descriptionChanged()));
    connect(ui->titleLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_titleChanged(QString)));
    connect(ui->fromLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_fromChanged(QString)));
    connect(ui->toLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_toChanged(QString)));
    connect(ui->dateLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_dateChanged(QString)));

    // set up style
    //Style::get_style(true);
    QString style = Style::get_style(true);
    this->setStyleSheet(style);

    ui->listView->get_model()->_storage->Load();

    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->listView->show_big_items(false);

//    ui->listView->get_model()->insertEntry(e);
  //  ui->listView->get_model()->insertEntry(e2);
//    ui->listView->get_model()->insertEntry(e3);
  //  ui->listView->get_model()->insertEntry(e4);

    //ui->listView->fill(el,1);
    ui->listView->select_row(0);

    manager = new TSManager();
}

Dialog::~Dialog()
{
    delete ui;
    delete manager;
}

void Dialog::on_listView_clicked(const QModelIndex &index)
{
    QVariant q = index.model();
    //QString qs = q.toString();

    Entry *e = ui->listView->get_selection();

    //Entry * e = model->GetEntryAtIndex(index);

    if (e != NULL)
    {
        ui->dateLineEdit->setText(e->date.toString("dd.MM.yyyy"));
        ui->fromLineEdit->setText(e->from.toString("hh:mm"));
        ui->toLineEdit->setText(e->to.toString("hh:mm"));
        ui->titleLineEdit->setText(e->title);
        ui->descriptionTextEdit->setText(e->description);
    }
}

void Dialog::on_titleChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();
    e->title = changedText;

    ui->listView->UpdateAndSave();
}

void Dialog::on_toChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();
    e->to = QTime::fromString(changedText, "hh:mm");

    ui->listView->UpdateAndSave();
}

void Dialog::on_fromChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();
    e->from = QTime::fromString(changedText, "hh:mm");

    ui->listView->UpdateAndSave();
}

void Dialog::on_dateChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();
    e->date = QDate::fromString(changedText, "dd.MM.yyyy");

    ui->listView->UpdateAndSave();
}

void Dialog::on_descriptionChanged()
{
    Entry *e = ui->listView->get_selection();

    e->description = ui->descriptionTextEdit->toPlainText();
    ui->listView->UpdateAndSave();
}

