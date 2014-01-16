#include "helper.h"

#include <QTextStream>
#include <QDebug>
#include <QStringRef>

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

bool Helper::write_file(QString filename, QString content)
{
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        return false;
    }

    QTextStream out(&file);
    out << content;
    file.close();

    return true;
}

QString Helper::getSharePath()
{

    QString path;
#ifndef Q_OS_WIN
    if(QFile::exists(_install_path + "/share/timesheet")) path = _install_path + "/share/timesheet/";
    else if(QFile::exists("/usr/share/sayonara")) path = "/usr/share/sayonara/";
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

QTime Helper::ConstructTime(QString time)
{
    // no input, no output :)
    // QTime timefrom = QTime());
    // timefrom will be a "null" time object, i.e. it's isNull() method will return true and isValid() will return false.

    if (time.isEmpty()) return QTime();

    //ok, basic formatting is like this
     QTime qt = QTime::fromString(time, "hh:mm");
     if (qt.isValid()) return qt;

     //not default time, try something else
     int length = time.length();

    if (length == 4)
    {
        QString hours = time.left(2);
        QString minutes = time.right(2);

        if ((hours.toInt() <= 23 ) && (minutes.toInt() <= 59))
            return QTime(hours.toInt(), minutes.toInt());
    }

    // return garbage...
    return QTime();
}

QDate Helper::ConstructDate(QString date)
{
    if (date.isEmpty()) return QDate();
    QDate qd = QDate::fromString(date, "dd.MM.yyyy");
    if (qd.isValid()) return qd;

    if (date == "0")
        return QDate::currentDate();

    if (date.length() == 1 || date.length() == 2)
    {
        // probably only day
        int iday = date.toInt();
        if (iday!=0)
            return QDate(QDate::currentDate().year(), QDate::currentDate().month(), iday);
    }

    //if nothing return today
    return QDate::currentDate();
}
