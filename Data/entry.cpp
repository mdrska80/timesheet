#include <QUuid>
#include "entry.h"

Entry::Entry()
{
    title = "";
    description = "";

    pl_selected = false;
    pl_playing = false;
    pl_dragged = false;
    is_disabled = false;

    id = QUuid::createUuid().toString();
    company = NULL;
    project = NULL;
}

Entry::~Entry()
{
    coll.clear();
}

bool Entry::operator<(const Entry &event)
{
    if (date == event.date)
    {
        return from < event.from;
    }

    if (!event.date.isValid())
    {
        return title.size() < event.title.size();
    }

    return date<event.date;
}

QString Entry::toXml(TSVersions ver)
{
    QString companyName = "";
    QString projectName = "";

    if (company != NULL)
        companyName = company->name;

    if (project != NULL)
        projectName = project->name;

    QString res = "";

    switch (ver)
    {
    case TSVersion_QT:

        //description = description.replace("<br/>","\n");

        res = QString("\t<Entry"
                              " id='%1'"
                              " date='%2'"
                              " from='%3'"
                              " to='%4'"
                              " project='%8'"
                              " company='%7'>\n"

                              "\t\t<Title>%5</Title>\n"
                              "\t\t<Description>%6</Description>\n"
                              "\t</Entry>\n\n"
                              )
                .arg(id)
                .arg(date.toString("dd.MM.yyyy"))
                .arg(from.toString("hh:mm"))
                .arg(to.toString("hh:mm"))
                .arg(title)
                .arg(description)
                .arg(companyName)
                .arg(projectName);

        res = res.replace("'","\"");
        break;
    case TSVersion_GTK_Autocont:
    {

        break;
    }

    default:
        break;
    }


    return res;
}

int Entry::GetDuration()
{
    int secs = from.secsTo(to);
    //int secondsTo = QTime().secsTo(to);
    //int secondsFrom = QTime().secsTo(from);

    return secs;//secondsTo - secondsFrom;
}

QString Entry::GetDurationAshhmm()
{
    // todo tohle je jeste nejak blbe
    int secs = GetDuration();
    int hours = secs/3600;
    int remainingMins = (secs - hours*3600)/60;

    QTime time(hours,remainingMins,0);
    return time.toString("hh:mm");
}

