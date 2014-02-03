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
    if (e!=NULL)
    {
        this->ui->titleLabel->setText(e->title);


        if (e->description.isEmpty())
            this->ui->descriptionLabel->setText(e->coll["Comment"]);
        else
            this->ui->descriptionLabel->setText(e->description);

        this->ui->dayLabel->setText(e->date.toString("dd"));

        this->ui->fromLabel->setText(QString("%1 - %2").arg(e->from.toString("hh:mm"),e->to.toString("hh:mm")));

        int secs = e->GetDuration();
        int hrs = secs / 3600;
        //QTimeSpan ts = e->to - e->from;

        if (hrs > 4)
            this->ui->durationLabel->setText("<font color='red'>"+e->GetDurationAshhmm()+"</font>");
        else
            this->ui->durationLabel->setText(e->GetDurationAshhmm());

        //qreal r = ts.toSecs();

        int worktime = 60*60*4;
        int percent = secs / (worktime / 100);

        ui->levels->set_level(percent,0);
    }
}
