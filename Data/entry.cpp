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

QString Entry::toXml()
{
    QString companyName = "";
    QString projectName = "";

    if (company != NULL)
        companyName = company->name;

    if (project != NULL)
        projectName = project->name;

    QString res = QString("\t<Entry"
                          " id='%1'"
                          " date='%2'"
                          " from='%3'"
                          " to='%4'"
                          " project='%8'"
                          " company='%7'>\r\n"

                          "\t\t<Title>%5</Title>\r\n"
                          "\t\t<Description>%6</Description>\r\n"
                          "\t</Entry>\r\n\r\n"
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

    return res;
}


