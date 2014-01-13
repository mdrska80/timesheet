#include "gui_entryentrybig.h"
#include "ui_gui_entryentrybig.h"

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

//    QString titlestr;

//    this->ui->lab_title->setText(titlestr);
//    this->ui->lab_artist->setText(md.artist.trimmed());
//    this->ui->lab_time->setText(Helper::cvtMsecs2TitleLengthString(md.length_ms));
}
