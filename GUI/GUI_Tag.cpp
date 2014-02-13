#include "GUI_Tag.h"
#include "ui_GUI_Tag.h"

GUI_Tag::GUI_Tag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI_Tag)
{
    ui->setupUi(this);
}

GUI_Tag::~GUI_Tag()
{
    delete ui;
}

QSize GUI_Tag::get_size()
{
    //set_text must be called first !!!

    // set new size
    int width = determineWidth()+8;
    int height = 32; // :)

    return QSize(width, height);
}

void GUI_Tag::set_tag(QString text, QColor color)
{
    this->color = color;

    ui->lbl->setText(text);
    innerText = text;
    this->setStyleSheet("QWidget {  border-radius: 3px; background-color : "+color.name()+"; }");

    // improve font
    QFont font = ui->lbl->font();
    //font.setPointSize(32);
    font.setWeight(QFont::Black);
    ui->lbl->setFont(font);

    // set new size
    QSize s = get_size();
    this->setMaximumHeight(s.height());
    this->setMaximumWidth(s.width());

    resize(s.width(), s.height());

    this->update();
}

int GUI_Tag::determineWidth()
{
    QLabel *l = ui->lbl;
    int width = l->fontMetrics().boundingRect(l->text()).width();
    return width;
}


