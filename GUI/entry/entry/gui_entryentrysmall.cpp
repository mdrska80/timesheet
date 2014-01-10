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

void GUI_EntryEntrySmall::setContent(Entry* e, int idx)
{

//    QString titlestr;
    this->ui->label_3->setText(e->title);

//    this->ui->lab_title->setText(titlestr);
//    this->ui->lab_artist->setText(md.artist.trimmed());
//    this->ui->lab_time->setText(Helper::cvtMsecs2TitleLengthString(md.length_ms));
}
