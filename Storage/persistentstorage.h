#ifndef PERSISTENTSTORAGE_H
#define PERSISTENTSTORAGE_H

#include <QList>

#include "Data/entry.h"

class PersistentStorage
{
public:
    PersistentStorage();

    virtual void Save(QList<Entry*>* entries)=0;

};

#endif // PERSISTENTSTORAGE_H
