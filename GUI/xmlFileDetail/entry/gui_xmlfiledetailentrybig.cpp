#include "gui_xmlfiledetailentrybig.h"
#include "ui_gui_xmlfiledetailentrybig.h"

GUI_XmlFileDetailEntryBig::GUI_XmlFileDetailEntryBig(QWidget *parent) :
    GUI_XmlFileDetailEntry(parent),
    ui(new Ui::GUI_XmlFileDetailEntryBig)
{
    ui->setupUi(this);
}

GUI_XmlFileDetailEntryBig::~GUI_XmlFileDetailEntryBig()
{
    delete ui;
}

void GUI_XmlFileDetailEntryBig::setContent(EntryFileInfo* md)
{
    ui->label_2->setText(QString::number(md->totalEntries) + " entries - "+QString::number(md->totalWorkedHours)+"h / 220h");
    QString qsMonth = QString("%1").arg(md->date.month(), 2, 'f', 0, '0');
    QString qsYear = QString("%1").arg(md->date.year(), 4, 'f', 0, '0');

    ui->yearLabel->setText(qsYear);
    ui->monthLabel->setText(qsMonth);
    //ui->companyLabel->setText("Unicorn");
    //ui->projectListLabel->setText("TSS");
    // do something...
}
