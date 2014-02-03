#ifndef FILTER_YESTERDAY_H
#define FILTER_YESTERDAY_H

#include "filterbase.h"
#include "../Data/entry.h"

class Filter_Yesterday : public FilterBase
{
public:
    Filter_Yesterday();
    virtual QList<Entry*> apply(QList<Entry*> entries);
};

#endif // FILTER_YESTERDAY_H
