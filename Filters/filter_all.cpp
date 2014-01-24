#include "filter_all.h"

Filter_All::Filter_All()
{
    name = "All";
    code = "ALL";
}

QList<Entry*> Filter_All::apply(QList<Entry*> entries)
{
    QList<Entry*> filtered;

    int cnt = entries.size();
    for (int i = 0;i<cnt;i++)
    {
        Entry *e = entries.at(i);
        HandleTodayHighlight(e);

        filtered.append(e);
    }

    Sort(&filtered);


    return filtered;
}

