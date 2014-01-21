#include "gui_entryentrybig.h"
#include "ui_gui_entryentrybig.h"

#include "Common/qtimespan.h"

GUI_EntryEntryBig::GUI_EntryEntryBig(QWidget *parent) :
    GUI_EntryEntry(parent),
    ui(new Ui::GUI_EntryEntryBig)
{
    ui->setupUi(this);
}

GUI_EntryEntryBig::~GUI_EntryEntryBig()
{
    delete ui;
}

void GUI_EntryEntryBig::setContent(Entry* e)
{
    if (e!=NULL)
    {
        this->ui->titleLabel->setText(e->title);
        this->ui->descriptionLabel->setText(e->description);
        this->ui->dayLabel->setText(e->date.toString("dd"));

        this->ui->fromLabel->setText(QString("%1 - %2").arg(e->from.toString("hh:mm"),e->to.toString("hh:mm")));

        QTimeSpan ts = e->to - e->from;
        this->ui->durationLabel->setText(ts.toString("hh:mm"));
    }
}
