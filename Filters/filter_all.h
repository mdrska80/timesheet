#ifndef FILTER_ALL_H
#define FILTER_ALL_H

#include "Filters/filterbase.h"
#include "Data/entry.h"

class Filter_All : public FilterBase
{
public:
    Filter_All();
    virtual QList<Entry*> apply(QList<Entry*> entries);

};

#endif // FILTER_ALL_H
