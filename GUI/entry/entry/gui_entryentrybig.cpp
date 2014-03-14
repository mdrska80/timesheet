#include "gui_entryentrybig.h"
#include "ui_gui_entryentrybig.h"
#include "../../../Common/helper.h"

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
        {
            QStringList lst = e->description.split('\n');
            int size = lst.size();

            QString text = lst[0];

            //remove new line and append ...
            text = text.replace("<br/>", "");

            if (size > 1)
                text += "...";

            this->ui->descriptionLabel->setText(text);
        }

        this->ui->dayLabel->setText(e->date.toString("dd"));

        this->ui->fromLabel->setText(QString("%1 - %2").arg(e->from.toString("hh:mm"),e->to.toString("hh:mm")));

        int secs = e->GetDuration();
        int hrs = secs / 3600;
        //QTimeSpan ts = e->to - e->from;

//        if (hrs > 4)
  //          this->ui->durationLabel->setText("<font color='red'>"+e->GetDurationAshhmm()+"</font>");
    //    else
            this->ui->durationLabel->setText(e->GetDurationAshhmm());

        QString evidedOvertime = "";
        if (e->overtime.isValid())
        {
            int scs =  e->overtime.hour()*60*60+e->overtime.minute()*60+e->overtime.second();
            evidedOvertime = "<font color='lightblue'></b> +"+Helper::GetSecsAsMin(scs)+"</b></font>";
        }

        this->ui->durationLabel->setText(this->ui->durationLabel->text()+"<br/>"+e->bustecDiff+evidedOvertime);


        //qreal r = ts.toSecs();
        if (e->description.contains("http"))
        {
            QString urls = e->GetUrlsAsTitles();
            ui->urlImageLabel->setText("<img src=':images/Earth-icon.png' width='24' title='"+urls+"'/>");
        }
        else
            ui->urlImageLabel->setText("");

//        ui->bustecLabel->setText(e->bustecDiff);

        int worktime = 60*60*4;
        int percent = secs / (worktime / 100);

        ui->levels->set_level(percent,0);
        ui->levels->setMaximumHeight(15);
    }

}

void GUI_EntryEntryBig::HandleTags(Entry *e)
{
    QString l = e->GetTagsAsText();
    QString current = ui->tag->textualTags;
    if (current != l)
    {
        qDebug() << "Start handling tags. Adding: " << l;
        QStringList sl = e->GetTags();
        ui->tag->set_tags(sl);
        ui->tag->textualTags = l;
        qDebug() << "End handling tags";
    }
}

