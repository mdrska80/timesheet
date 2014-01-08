#include "dialog.h"
#include "ui_dialog.h"

#include <QStandardItemModel>
#include <QListView>

#include <QDebug>
#include "entrylistmodel.h"

#include "style.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // set up style
    QString style = Style::get_style(true);
    this->setStyleSheet(style);

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

    ui->listView->setModel(model);
    ui->tableView->setModel(model);

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
    QString qs = q.toString();

    Entry * e = model->GetEntryAtIndex(index);
    ui->textEdit->setText(e->title);
    ui->textEdit_2->setText(e->ConvertToXml());

    QString DBStatus = manager->db->CheckDb();
    ui->DBStatus_label->setToolTip(DBStatus);

    if (DBStatus == NULL)
        ui->DBStatus_label->setText("<font color='green'>ONLINE</font>");
    else
    {
        ui->DBStatus_label->setText("<font color='red'>OFFLINE</font>");
    }
}
