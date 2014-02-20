#ifndef BUSTECDOCHAZKA_H
#define BUSTECDOCHAZKA_H

#include "bustecentry.h"

class BustecDochazka
{
public:
    BustecDochazka();

    void Process(QString inputStr);
    BustecEntry* ProcessRow(QString s);
    void CleanEntries();
    QList<BustecEntry*> GetEntriesByDate(QDate date);
    int IsDayFullFilled(QDate date);

    //helper methods
    QDate ParseDate(QString in);
    QTime ParseTime(QString in);
    int GetDuration(QDate date);
    int GetDuration(QTime from, QTime to);

    QTime GetPrichod(QList<BustecEntry*> lst);
    QTime GetOdchod(QList<BustecEntry*> lst);

    bool GetFromToByDate(QDate dt, QTime &from, QTime &to);





    QList<BustecEntry*> bentries;
};

#endif // BUSTECDOCHAZKA_H
