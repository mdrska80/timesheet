#include "helper.h"

static QString _install_path = "";

bool Helper::read_file_into_str(QString filename, QString* content)
{

    QFile file(filename);
    content->clear();
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    while (!file.atEnd()) {
        QByteArray arr = file.readLine();
        QString str = QString::fromLocal8Bit(arr);

        content->append(str);
    }

    file.close();

    if(content->size() > 0 ){
        return true;
    }

    return false;
}

QString Helper::getSharePath()
{

    QString path;
#ifndef Q_OS_WIN
    if(QFile::exists(_install_path + "/share/timesheet")) path = _install_path + "/share/timesheet/";
    else if(QFile::exists("/usr/share/timesheet")) path = "/usr/share/timesheet/";
    else path = "";
#else
    path = QDir::homePath() + QString("\\.timesheet\\images\\");
    if(QFile::exists(path)){
        return path;
    }
    else path = "";
#endif

    return path;

}
