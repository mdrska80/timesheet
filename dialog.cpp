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

    Entry *e2 = new Entry();
    e2->title = "titulek 2";
    e2->color = QColor(255, 0, 255, 255);
    e2->date = QDate::currentDate();
    e2->from = QTime::currentTime().addSecs(-3600);
    e2->to = QTime::currentTime();
    e2->description = "popis pozadavku, komplexni popis";


    QList<Entry*> items;
       items.append(e);
       items.append(e2);
       items.append(e);

       model = new EntryListModel(items, this);

       model->setHeaderData(0, Qt::Horizontal, "test", Qt::DisplayRole);

//    model = new QStandardItemModel(2, 1, this);
//    QStandardItem *qsi = new QStandardItem(QString("test"));
  //  qsi->setData(QVariant(QVariant::UserType, e));

//    model->appendRow(qsi);
  //  model->appendRow(new QStandardItem(QString("John Smith\nSalary: %1, %2\n")));
    //model->appendRow(new QStandardItem(QString("Max Mustermann\nSalary: %1, ") + QString("000\n")));

    ui->listView->setModel(model);
    ui->tableView->setModel(model);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_listView_clicked(const QModelIndex &index)
{
    QVariant q = index.model();
    QString qs = q.toString();

    Entry * e = model->GetEntryAtIndex(index);
    ui->textEdit->setText(e->title);

    ui->textEdit_2->setText(e->ConvertToXml());
    //model->
    //index.data().value();
    //Entry* p = static_cast<Entry*>(index.data().value());
    //qDebug() << p->title;
}
