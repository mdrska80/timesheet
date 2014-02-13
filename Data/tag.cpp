#include "tag.h"

Tag::Tag()
{
}


QString Tag::toXml()
{
    QString res = QString("\t<Tag code='%1' color='%2' />\n")
            .arg(code)
            .arg(color.name());

    res = res.replace("'","\"");

    return res;
}

