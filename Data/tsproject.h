#ifndef TSPROJECT_H
#define TSPROJECT_H

#include <QString>
#include <QColor>

class TSProject
{
public:
    TSProject();

    // unique id of the project
    QString id;

    // Name of the project
    QString name;

    // Understandable description of the project
    QString description;

    // Id of the parent project
    QString parentId;

    // Color of the project
    QColor color;
};

#endif // TSPROJECT_H
