#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QColor>

class Project
{
public:
    Project();

    // unique id of the project
    QString id;

    // Name of the project
    QString name;

    // Understandable description of the project
    QString description;

    // Id of the parent project
    Project* parent;

    // Color of the project
    QColor color;

    //methods
    QString toXml();
};

#endif // PROJECT_H
