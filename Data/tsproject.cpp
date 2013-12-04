#include "tsproject.h"

TSProject::TSProject()
{
}

QString TSProject::ConvertToXml()
{
    QString res = QString("<Project id='%1'"
                          " parentId='%2'"
                          " name='%3'"
                          " description='%4'"
                          " color='%5' />\r\n"
                          )
            .arg(id)
            .arg(parentId)
            .arg(name)
            .arg(description)
            .arg(color.name());

    res = res.replace("'","\"");

    return res;
}
