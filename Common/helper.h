#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTime>
//#include "qtimespan.h"

const QString colorRed = "#72424e";
const QString colorRedDark = "#2f3751";
const QString colorRedPoison = "#ff0000";
const QString colorBlack = "#000000";


const QString colorGreen = "#42724e";
const QString colorYellow = "#d2e24e";
const QString colorGreenDark = "#372f51";


class Helper
{
public:
    static void InitializeStatic();


    static bool read_file_into_str(QString filename, QString* content);
    static bool write_file(QString filename, QString content);

    static QTime ConstructTime(QString time);
    static QDate ConstructDate(QString date);

    static QString get_fg_color(int val_bg);

    static QString GetSecsAshhmm(int secs);
    static QString GetSecsAsMin(int secs);
    static int TimeToSecs(QTime time);

    static int GetDuration(QTime from, QTime to);

    static QTime RoundTimeDown(QTime time);
    static QTime RoundTimeUp(QTime time);



};

#endif // HELPER_H
