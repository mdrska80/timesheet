#include "helper.h"

#include <QTextStream>
#include <QDebug>
#include <QStringRef>
#include <QDir>

static QString _install_path = "";

bool Helper::read_file_into_str(QString filename, QString* content)
{

    QFile file(filename);
    content->clear();
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");
    content->append(in.readAll());

    file.close();

    if(content->size() > 0 ){
        return true;
    }

    return false;
}

bool Helper::write_file(QString filename, QString content)
{
    QString executablePth = QDir::currentPath();
    QFile file(executablePth+"/"+filename);

    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        return false;
    }


    QTextStream out(&file);
    out.setCodec("UTF-8");
    out << content;
    file.close();

    return true;
}

QString Helper::getSharePath()
{

    QString path;
    QString executablePth = QDir::currentPath();

#ifndef Q_OS_WIN

    if(QFile::exists(_install_path + "/share/timesheet")) path = _install_path + "/share/timesheet/";
    //else if(QFile::exists("/usr/share/sayonara")) path = "/usr/share/sayonara/";
    else if(QFile::exists(executablePth+"/share")) path = executablePth+"/share/";
    else path = "";
#else
    path = QDir::homePath() + QString("\\.timesheet\\images\\");
    if(QFile::exists(path)){
        return path;
    }
    else if(QFile::exists(executablePth+"/share")) path = executablePth+"/share/";
    else
        path = "";
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

    if (length <= 2 )
    {
        QString hours = time;
        QString minutes = 0;

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

QString Helper::get_fg_color(int val_bg)
{

    if(val_bg > 160)
        return  QString(" color: #202020; ");

    else
        return QString(" color: #D8D8D8 ");
}

QTime Helper::NumberToTime(double number)
{
    int hours = (int)number;
    double minutes = number - hours;
    int newMinutes = minutes * 60 ;

    return QTime(hours,newMinutes,00);
}

QString Helper::GetSecsAshhmm(int secs)
{
    int hours = secs/3600;
    int remainingMins = (secs - hours*3600)/60;

    QTime time(hours,remainingMins,0);
    return time.toString("hh:mm");
}

QString Helper::GetSecsAsMin(int secs)
{
    return QString::number(secs/60)+" min";
}
