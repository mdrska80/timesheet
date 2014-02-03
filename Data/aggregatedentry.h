#ifndef AGGREGATEDENTRY_H
#define AGGREGATEDENTRY_H

#include <QList>
#include "entry.h"

class AggregatedEntry
{
public:
    AggregatedEntry();

    // which entries are part of this aggregated entry
    // we can display tooltip with titles on list display
    QList<Entry*> entries;

    // what day we are in
    QDate date;

    // is it sunday or saturday?
    bool isWorkingDay;

    // total working time in seconds.
    int agregatedTime;

    // methods
    void init();
};

#endif // AGGREGATEDENTRY_H
