#ifndef FILTER_TODAY_H
#define FILTER_TODAY_H

#include "filterbase.h"
#include "../Data/entry.h"

class Filter_Today : public FilterBase
{
public:
    Filter_Today();

    virtual QList<Entry*> apply(QList<Entry*> entries);

};

#endif // FILTER_TODAY_H
