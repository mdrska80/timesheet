#include "filter_yesterday.h"

Filter_Yesterday::Filter_Yesterday()
{
    name = "Yesterday";
    code = "YESTERDAY";
}


QList<Entry*> Filter_Yesterday::apply(QList<Entry*> entries)
{
    QList<Entry*> filtered;

    int cnt = entries.size();

    for (int i = 0;i<cnt;i++)
    {
        Entry *e = entries.at(i);
        HandleTodayHighlight(e);

        if (e->date == QDate::currentDate().addDays(-1))
            filtered.append(e);
    }


    return filtered;
}
