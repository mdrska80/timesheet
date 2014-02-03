#ifndef FILTER_INVALID_H
#define FILTER_INVALID_H

#include "filterbase.h"
#include "../Data/entry.h"

class Filter_Invalid : public FilterBase
{
public:
    Filter_Invalid();
    virtual QList<Entry*> apply(QList<Entry*> entries);

};

#endif // FILTER_INVALID_H
