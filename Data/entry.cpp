#include "entry.h"

Entry::Entry()
{
}

QString Entry::ConvertToXml()
{
    QString res = QString("<Entry date='%1'"
                          " from='%2'"
                          " to='%3'"
                          " title='%4'>\r\n"

                          "\t<Description>\r\n"
                          "\t\t%5\r\n"
                          "\t</Description>\r\n"
                          "</Entry>\r\n"
                          )
            .arg(date.toString("dd.MM.yyyy"))
            .arg(from.toString())
            .arg(to.toString())
            .arg(title)
            .arg(description);

    res = res.replace("'","\"");

    return res;
}

