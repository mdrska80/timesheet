#include "dialog.h"
#include "ui_dialog.h"

#include <QStandardItemModel>
#include <QListView>

#include <QDebug>
#include "entrylistmodel.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    Entry *e = new Entry();
    e->title = "titulek";
    e->color = QColor(255, 0, 0, 255);

    QList<Entry*> items;
       items.append(e);
       items.append(e);
       items.append(e);

       EntryListModel* elm = new EntryListModel(items, this);



//    model = new QStandardItemModel(2, 1, this);
//    QStandardItem *qsi = new QStandardItem(QString("test"));
  //  qsi->setData(QVariant(QVariant::UserType, e));

//    model->appendRow(qsi);
  //  model->appendRow(new QStandardItem(QString("John Smith\nSalary: %1, %2\n")));
    //model->appendRow(new QStandardItem(QString("Max Mustermann\nSalary: %1, ") + QString("000\n")));

    ui->listView->setModel(elm);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_listView_clicked(const QModelIndex &index)
{
    //index.data().value();
    //Entry* p = static_cast<Entry*>(index.data().value());
    //qDebug() << p->title;
}
