#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QFile>
#include <QIODevice>

class Helper
{
public:
    static bool read_file_into_str(QString filename, QString* content);
    static QString getSharePath();
};

#endif // HELPER_H
