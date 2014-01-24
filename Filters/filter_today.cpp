#include "filter_today.h"

Filter_Today::Filter_Today()
{
    name = "Today";
    code = "TODAY";
}

QList<Entry*> Filter_Today::apply(QList<Entry*> entries)
{
    QList<Entry*> filtered;

    int cnt = entries.size();
    for (int i = 0;i<cnt;i++)
    {
        Entry *e = entries.at(i);
        HandleTodayHighlight(e);

        if (e->date == QDate::currentDate())
            filtered.append(e);
    }

    return filtered;
}
