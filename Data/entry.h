#ifndef ENTRY_H
#define ENTRY_H

#include <QDate>
#include <QTime>
#include <QColor>
#include <QVariant>
#include <QStringList>

#include <vector>

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

    bool pl_selected;
    bool pl_dragged;
    bool pl_playing;
    bool is_disabled;

    //parent entry, mostly empty
    Entry* parent;

    //methods
    QString toXml();
    static Entry* fromXml();


    QVariant toVariant() const{

        QStringList list;

        list.push_back(QString::number(id));
        list.push_back(date.toString("dd.MM.yyyy"));
        list.push_back(from.toString());
        list.push_back(to.toString());
        list.push_back(title);
        list.push_back(description);
        list.push_back(pl_selected ? "1" : "0");
        list.push_back(pl_dragged ? "1" : "0");
        list.push_back(pl_playing ? "1" : "0");
        list.push_back(is_disabled ? "1" : "0");


        return list;
    }

    static bool fromVariant(QVariant v, Entry* md){

        QStringList list = v.toStringList();

        //if(list.size() < 24) return false;

        //find correct one....

        md->id =             list[0].toInt();
        md->date =           QDate::fromString(list[1], "dd.MM.yyyy");
        md->from =           QTime::fromString(list[2]);
        md->to =             QTime::fromString(list[3]);
        md->title =          list[4];
        md->description =    list[5];
        md->pl_selected =    list[6] == "1";
        md->pl_dragged =     list[7] == "1";
        md->pl_playing =     list[8] == "1";
        md->is_disabled =     list[9] == "1";



        return true;
    }
};


class EntryList : public std::vector<Entry*>
{

public:

    EntryList(){}
    ~EntryList(){
        clear();
    }
};

#endif // ENTRY_H
