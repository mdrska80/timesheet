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
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_titleChanged(QString)));

    // set up style
    //Style::get_style(true);
    QString style = Style::get_style(true);
    this->setStyleSheet(style);

    Entry *e = new Entry();
    e->title = "titulek";
    e->color = QColor(255, 0, 0, 255);
    e->pl_playing = true;
    e->date = QDate::currentDate();

    Entry *e2 = new Entry();
    e2->title = "titulek 2";
    e2->color = QColor(255, 0, 255, 255);
    e2->date = QDate::currentDate();
    e2->from = QTime::currentTime().addSecs(-3245);
    e2->to = QTime::currentTime();
    e2->description = "popis pozadavku, komplexni popis";

    Entry *e3 = new Entry();
    e3->title = "titulek3";
    e3->is_disabled = true;
    e3->date = QDate::currentDate();


    //QList<Entry*> items;
    //items.append(e);
    //items.append(e2);
    //items.append(e3);

    //model = new EntryListModel(items, this);

    //model->setHeaderData(0, Qt::Horizontal, "test", Qt::DisplayRole);
    //ui->listView->setAlternatingRowColors(true);

    //ui->listView->setModel(model);


    EntryList el;
    el.push_back(e2);
    el.push_back(e);
    el.push_back(e3);
    el.push_back(e3);
    el.push_back(e);

    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->listView->show_big_items(false);

    ui->listView->get_model()->insertEntry(e);
    ui->listView->get_model()->insertEntry(e2);
    ui->listView->get_model()->insertEntry(e2);

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
        ui->lineEdit->setText(e->title);
        ui->textEdit_2->setText(e->toXml());

        QString DBStatus = manager->db->CheckDb();
        //ui->DBStatus_label->setToolTip(DBStatus);

        //if (DBStatus == NULL)
        //    ui->DBStatus_label->setText("<font color='green'>ONLINE</font>");
        //else
        //{
        //    ui->DBStatus_label->setText("<font color='red'>OFFLINE</font>");
        //}
    }
}

void Dialog::on_titleChanged(QString changedText)
{
    Entry *e = ui->listView->get_selection();
    e->title = changedText;

    ui->listView->update();
}

void Dialog::Save()
{
    int max = ui->listView->get_model()->entries.size();
    QString qs = "<Entries>\r\n";

    for(int i = 0;i<max;i++)
    {
        Entry* e = ui->listView->get_model()->entries[i];
        qs.append(e->toXml());
        //qDebug() << e->title;
    }

    //finalize xml
    qs.append("</Entries>");
    Helper::write_file("test.xml", qs);
}
