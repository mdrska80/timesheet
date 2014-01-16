#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTime>
#include "qtimespan.h"

class Helper
{
public:
    static bool read_file_into_str(QString filename, QString* content);
    static bool write_file(QString filename, QString content);
    static QString getSharePath();

    static QTime ConstructTime(QString time);
    static QDate ConstructDate(QString date);

};

#endif // HELPER_H
