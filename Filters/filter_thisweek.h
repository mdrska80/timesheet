#ifndef FILTER_THISWEEK_H
#define FILTER_THISWEEK_H

#include "filterbase.h"
#include "../Data/entry.h"


class Filter_Thisweek : public FilterBase
{
public:
    Filter_Thisweek();

    virtual QList<Entry*> apply(QList<Entry*> entries);
};

#endif // FILTER_THISWEEK_H
