#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QColor>
#include <QDate>

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

    QDate from;
    QDate to;

    //methods
    QString toXml();
};

#endif // PROJECT_H
