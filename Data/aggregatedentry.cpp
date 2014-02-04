#include "aggregatedentry.h"

AggregatedEntry::AggregatedEntry()
{

}

void AggregatedEntry::init()
{
    int max = entries.size();

    for(int i = 0;i<max;i++)
    {
        Entry* e = entries.at(i);
        agregatedTime += e->GetDuration();
    }

    isWorkingDay = (date.dayOfWeek() == 6 || date.dayOfWeek() == 7);
}
