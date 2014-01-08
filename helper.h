#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QFile>
#include <QIODevice>

namespace Helper
{
    bool read_file_into_str(QString filename, QString* content);
    QString getSharePath();
};

#endif // HELPER_H
