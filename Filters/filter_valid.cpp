#include "filter_valid.h"

Filter_Valid::Filter_Valid()
{
    name = "Valid";
    code = "VALID";
}

QList<Entry*> Filter_Valid::apply(QList<Entry*> entries)
{
    QList<Entry*> filtered;

    int cnt = entries.size();

    for (int i = 0;i<cnt;i++)
    {
        Entry *e = entries.at(i);
        if (highlightTodayEntries)
            e->pl_playing = e->date == QDate::currentDate();

        if (e->date.isValid() && e->from.isValid() && e->to.isValid())
            filtered.append(e);
    }

    return filtered;
}

