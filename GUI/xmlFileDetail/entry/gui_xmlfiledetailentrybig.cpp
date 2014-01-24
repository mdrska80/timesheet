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
    QString qs = QString("%1 entries - %2h / %3h (%4 days)")
            .arg(QString::number(md->entryCount))
            .arg(QString::number(md->workedHours))
            .arg(QString::number(md->workingHours))
            .arg(QString::number(md->workingHours/8));

    ui->label_2->setText(qs);
    QString qsMonth = QString("%1").arg(md->date.month(), 2, 'f', 0, '0');
    QString qsYear = QString("%1").arg(md->date.year(), 4, 'f', 0, '0');

    ui->yearLabel->setText(qsYear);
    ui->monthLabel->setText(qsMonth);
    QString percents = QString("%1").arg(md->workedHours/(md->workingHours/100), 2, 'f', 0, '0');
    ui->percentLabel->setText(percents+"%");

    SetImage(md);
}

void GUI_XmlFileDetailEntryBig::SetImage(EntryFileInfo* md)
{
    ui->imageLabel->setText("<img src=':images/Earth-icon.png' width='24' />");

    Company* c = TSCore::I().GetCompany(md->date);
    if (c != NULL)
    {
        ui->imageLabel->setText("<img src=':images/"+c->name+"' width='24' />");
    }


}
