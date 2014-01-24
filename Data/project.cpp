#include "project.h"

Project::Project()
{
}

QString Project::toXml()
{
    QString res = QString("\t<Project id='%1'"
                          " from='%2'"
                          " to='%3'"
                          " name='%4'>\r\n"
                          "\t\t<Description>%5</Description>\r\n"
                          "\t</Project>\r\n\r\n"
                          )
            .arg(id)
            .arg(from.toString("dd.MM.yyyy"))
            .arg(to.toString("dd.MM.yyyy"))
            .arg(name)
            .arg(description);

    res = res.replace("'","\"");

    return res;
}
