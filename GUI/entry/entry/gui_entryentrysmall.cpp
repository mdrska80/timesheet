#include "gui_entryentrysmall.h"
#include "ui_gui_entryentrysmall.h"

GUI_EntryEntrySmall::GUI_EntryEntrySmall(QWidget *parent) :
    GUI_EntryEntry(parent),
    ui(new Ui::GUI_EntryEntrySmall)
{
    ui->setupUi(this);
}

GUI_EntryEntrySmall::~GUI_EntryEntrySmall()
{
    delete ui;
}

void GUI_EntryEntrySmall::setContent(Entry* e)
{
    this->ui->titleLabel->setText(e->title);
    this->ui->dayLabel->setText(e->date.toString("dd"));
    this->ui->fromToLabel->setText(QString("%1 - %2").arg(e->from.toString("hh:mm"),e->to.toString("hh:mm")));

    this->ui->durationLabel->setText(e->GetDurationAshhmm());
}
