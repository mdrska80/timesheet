#include "filterbase.h"

FilterBase::FilterBase()
{
}

template<class T>
bool dereferencedLessThan(T * o1, T * o2) {
    return *o1 < *o2;
}

void FilterBase::HandleTodayHighlight(Entry *e)
{
    if (highlightTodayEntries)
        e->pl_playing = e->date == QDate::currentDate();
    else
        e->pl_playing = false;
}

void FilterBase::Sort(QList<Entry*>* filtered)
{
    qSort(filtered->begin(), filtered->end(), dereferencedLessThan<Entry>);
}
