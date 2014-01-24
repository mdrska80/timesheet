#include "filter_invalid.h"

Filter_Invalid::Filter_Invalid()
{
    name = "Invalid";
    code = "INVALID";
}

QList<Entry*> Filter_Invalid::apply(QList<Entry*> entries)
{
    QList<Entry*> filtered;

    int cnt = entries.size();
    for (int i = 0;i<cnt;i++)
    {
        Entry *e = entries.at(i);
        HandleTodayHighlight(e);

        if (!e->date.isValid() || !e->from.isValid() || !e->to.isValid())
            filtered.append(e);
    }


    return filtered;
}
