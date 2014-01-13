#include "project.h"

Project::Project()
{
}

QString Project::toXml()
{
    QString parentName = "";

    if (parent != NULL)
        parentName = parent->name;

    QString res = QString("<Project id='%1'"
                          " parentId='%2'"
                          " name='%3'"
                          " description='%4' />\r\n"
                          )
            .arg(id)
            .arg(parentName)
            .arg(name)
            .arg(description);

    res = res.replace("'","\"");

    return res;
}
