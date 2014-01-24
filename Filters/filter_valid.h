#ifndef FILTER_VALID_H
#define FILTER_VALID_H

#include "Filters/filterbase.h"
#include "Data/entry.h"

class Filter_Valid : public FilterBase
{
public:
    Filter_Valid();

    virtual QList<Entry*> apply(QList<Entry*> entries);

};

#endif // FILTER_VALID_H
