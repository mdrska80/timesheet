#include "company.h"

Company::Company()
{
}


QString Company::toXml()
{
    QString res = QString("\t<Company"
                          " id='%1'"
                          " from='%2'"
                          " to='%3'"
                          " name='%4'"
                          " url='%5'>\r\n"
                          "\t\t<Description>%6</Description>\r\n"
                          "\t</Company>\r\n\r\n"
                          )
            .arg(id)
            .arg(from.toString("dd.MM.yyyy"))
            .arg(to.toString("dd.MM.yyyy"))
            .arg(name)
            .arg(url)
            .arg(description);

    res = res.replace("'","\"");

    return res;
}

