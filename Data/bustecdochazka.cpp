#include "bustecdochazka.h"

BustecDochazka::BustecDochazka()
{
}

void BustecDochazka::Process(QString inputStr)
{
    //udela z hromady textu ....strukturu :)

    //Clean
    CleanEntries();

    QStringList lst = inputStr.split('\n');

    foreach(QString s, lst)
    {
        BustecEntry *e = ProcessRow(s);

        if (e != NULL)
            bentries.append(e);
    }
}

BustecEntry* BustecDochazka::ProcessRow(QString s)
{
    // it is tab delimited row
    // 3.2.2014 17:16:00	1	PRICHOD DO PRACE	1	0059836130	XXXXXXX

    // so ...

    QStringList lst = s.split('\t');

    if (lst.size() != 6) return NULL;           // nejeky jiny format
    if (lst[0] == "Datum a čas") return NULL;   // hlavicka, ta nas take nezajima

    // teprve ted ma smysl vytvaret kontejner
    BustecEntry *entry = new BustecEntry();
    entry->Date = ParseDate(lst[0]);
    entry->Time = ParseTime(lst[0]);
    entry->Action = lst[1].toInt();
    entry->ActionName = lst[2];
    entry->Terminal = lst[3].toInt();
    entry->Surname = lst[4];
    entry->Name = lst[5];

    return entry;
}

QDate BustecDochazka::ParseDate(QString in)
{
    QStringList lst = in.split(' ');
    QDate dt = QDate::fromString(lst[0],"d.M.yyyy");
    return dt;
}

QTime BustecDochazka::ParseTime(QString in)
{
    QStringList lst = in.split(' ');
    QTime dt = QTime::fromString(lst[1],"hh:mm:ss");
    return dt;
}


void BustecDochazka::CleanEntries()
{
    int cnt = bentries.size();

    for (int i = 0;i<cnt;i++)
    {
        delete bentries.at(i);
    }

    bentries.clear();
}

int BustecDochazka::IsDayFullFilled(QDate date)
{
    QList<BustecEntry*> lst = GetEntriesByDate(date);
    return -1;
}

bool BustecDochazka::GetFromToByDate(QDate date, QTime &from, QTime &to)
{
    QList<BustecEntry*> lst = GetEntriesByDate(date);

    if (lst.size()==0) return false;

    from = GetPrichod(lst);
    to = GetOdchod(lst);
    return true;
}

int BustecDochazka::GetDuration(QDate date)
{
    QList<BustecEntry*> lst = GetEntriesByDate(date);

    QTime from = GetPrichod(lst);
    QTime to = GetOdchod(lst);

    int durInSecs = GetDuration(from, to);
    return durInSecs;
}

QList<BustecEntry*> BustecDochazka::GetEntriesByDate(QDate date)
{
    QList<BustecEntry*> lst;

    int cnt = bentries.size();
    for(int i = 0; i<cnt;i++)
    {
        BustecEntry *e = bentries[i];

        if (e->Date == date)
            lst.append(e);
    }
    return lst;
}

int BustecDochazka::GetDuration(QTime from, QTime to)
{
    int secs = from.secsTo(to);
    return secs;
}

QTime BustecDochazka::GetPrichod(QList<BustecEntry*> lst)
{
    // hledam neco s akci 1 a nejmensim case
    QTime time;
    time.setHMS(23,59,59);

    int cnt = lst.size();
    for(int i = 0; i<cnt;i++)
    {
        BustecEntry *e = lst[i];

        if (e->Action == 1)
        {
            if (time > e->Time)
                time = e->Time;
        }
    }
    return time;
}

QTime BustecDochazka::GetOdchod(QList<BustecEntry*> lst)
{
    // hledam neco s akci 2 a nejvyssim cas
    QTime time;
    time.setHMS(0,0,0);

    int cnt = lst.size();
    for(int i = 0; i<cnt;i++)
    {
        BustecEntry *e = lst[i];

        if (e->Action == 2)
        {
            if (time < e->Time)
                time = e->Time;
        }
    }

    return time;
}


