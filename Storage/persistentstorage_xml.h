#ifndef PERSISTENTSTORAGE_XML_H
#define PERSISTENTSTORAGE_XML_H

#include <QList>

#include "Data/entry.h"
#include "persistentstorage.h"

class PersistentStorage_XML : public PersistentStorage
{
public:
    PersistentStorage_XML();

    virtual void Save(QList<Entry*>* entries);
};

#endif // PERSISTENTSTORAGE_XML_H
