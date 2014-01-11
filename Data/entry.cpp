#include "entry.h"

Entry::Entry()
{
    pl_selected = false;
    pl_playing = false;
    pl_dragged = false;
    is_disabled = false;
}

QString Entry::toXml()
{
    QString res = QString("\t<Entry date='%1'"
                          " from='%2'"
                          " to='%3'"
                          " title='%4'>\r\n"

                          "\t\t<Description>\r\n"
                          "\t\t\t%5\r\n"
                          "\t\t</Description>\r\n"
                          "\t</Entry>\r\n"
                          )
            .arg(date.toString("dd.MM.yyyy"))
            .arg(from.toString())
            .arg(to.toString())
            .arg(title)
            .arg(description);

    res = res.replace("'","\"");

    return res;
}

Entry* Entry::fromXml()
{

}


