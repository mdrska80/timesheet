#include "GUI_Tags.h"
#include "ui_GUI_Tags.h"

GUI_Tags::GUI_Tags(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI_Tags)
{
    ui->setupUi(this);
}

GUI_Tags::~GUI_Tags()
{
    delete ui;
}

void GUI_Tags::set_tags(QStringList lst)
{
    int maxWidth = 0;
    int spaceBetweenTags = 5;

    //clear existing tags
    clear_removed(lst);
    QColor defColor(255,255,255);

    foreach(QString s, lst)
    {
        bool bFound = find_tag(s);

        if (!bFound)
        {
            GUI_Tag* guit = new GUI_Tag(this);

            Tag *t = TSCore::I().GetTag(s);
            if (t!=NULL)
                guit->set_tag(t->code, t->color);
            else
                guit->set_tag(s, defColor);

            maxWidth += guit->get_size().width()+spaceBetweenTags;

            tagControls.append(guit);
            ui->horizontalLayout->addWidget(guit);
        }
    }

    this->setMaximumWidth(maxWidth);
}

bool GUI_Tags::find_tag(QString tag)
{
    foreach(GUI_Tag* t, tagControls)
    {
        if (t->innerText == tag) return true;
    }

    return false;
}

void GUI_Tags::clear_removed(QStringList lst)
{
    int cnt = tagControls.size();

    for (int i = 0; i< cnt;i++)
    {
        GUI_Tag* t = tagControls.at(i);

        // delete if found but not in new
        if (!lst.contains(t->innerText))
            ui->horizontalLayout->removeWidget(t);
    }
}
