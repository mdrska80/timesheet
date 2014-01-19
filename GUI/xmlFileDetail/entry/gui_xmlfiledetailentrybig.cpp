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
    // do something...
}
