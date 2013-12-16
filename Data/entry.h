#ifndef ENTRY_H
#define ENTRY_H

#include <QDate>
#include <QTime>
#include <QColor>

class Entry
{

public:
    Entry();

    // id of entry from DB
    int id;

    // Zakladni casove udaje.
    QDate date;
    QTime from;
    QTime to;

    // Tohle je to co bude videt. Jednoduchy a strucny popisek
    QString title;

    // Detailnejsi popis toho co jsem delal.
    QString description;

    QColor color;

    //parent entry, mostly empty
    Entry* parent;

    //methods
    QString ConvertToXml();
};

#endif // ENTRY_H
