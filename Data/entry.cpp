#include <QUuid>
#include "entry.h"
#include "../Common/helper.h"

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

        // for sure
        description = description.replace("<br/>","\n");

        res = QString("\t<Entry"
                              " id='%1'"
                              " date='%2'"
                              " from='%3'"
                              " to='%4'"
                              " overtime='%9'"
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
                .arg(projectName)
                .arg(overtime.toString("hh:mm"));

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
    return Helper::GetDuration(from, to);
}

QString Entry::GetDurationAshhmm()
{
    int secs = GetDuration();
    return Helper::GetSecsAshhmm(secs);
}

QStringList Entry::GetUrls()
{
    QStringList lResult;
    //get all urls in description.
    QStringList lst = description.split("http");

    int cnt = lst.size();
    for(int i = 1;i<cnt;i++)
    {
        QString str = lst[i];

        int firstSpaceIndex = str.indexOf(' ',0);
        QString strUrl = "http"+str.left(firstSpaceIndex);

        lResult.append(strUrl);
    }

    return lResult;
}

QString Entry::GetUrlsAsTitles()
{
    QStringList lst = GetUrls();
    QString result;

    foreach(QString s, lst)
    {
        result += s + "\n";
    }

    return result;
}

QStringList Entry::GetTags()
{
    QStringList lResult;
    //get all urls in description.
    QStringList lst = description.split("#");

    int cnt = lst.size();
    for(int i = 1;i<cnt;i++)
    {
        QString str = lst[i];

        int firstSpaceIndex = str.indexOf(' ',0);
        QString strTag = str.left(firstSpaceIndex);

        lResult.append(strTag);
    }

    return lResult;
}

QString Entry::GetTagsAsText()
{
    QStringList lst = GetTags();
    QString result;

    foreach(QString s, lst)
    {
        if (s!="")
            result += s + ", ";
    }

    return result;
}

