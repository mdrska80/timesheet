#include "filter_thisweek.h"

Filter_Thisweek::Filter_Thisweek()
{
    name = "This week";
    code = "THIS_WEEK";
}


QList<Entry*> Filter_Thisweek::apply(QList<Entry*> entries)
{
    QList<Entry*> filtered;

    int cnt = entries.size();

    QDate qdBegin;
    QDate qdEnd;
    QDate qdToday = QDate::currentDate();

    //determine begin and end.

    //monday = 1;
    int dayOfWeek = qdToday.dayOfWeek();
    int day = qdToday.day();

    // co kdyz to presahne mesic? dozadu?
    qdBegin = QDate(qdToday.year(), qdToday.month(), day - (dayOfWeek-1));
    qdEnd =  QDate(qdToday.year(), qdToday.month(), 7 - dayOfWeek + day);

    for (int i = 0;i<cnt;i++)
    {
        Entry *e = entries.at(i);
        HandleTodayHighlight(e);

        if (e->date >= qdBegin && e->date <= qdEnd)
            filtered.append(e);
    }

    return filtered;
}

