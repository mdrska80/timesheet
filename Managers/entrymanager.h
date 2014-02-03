#ifndef ENTRYMANAGER_H
#define ENTRYMANAGER_H

#include <QList>
#include "../Data/entry.h"
#include "tsmanager.h"

class TSManager;

//all entry logic is handled here
class EntryManager
{
public:
    EntryManager(TSManager* mgr);
    ~EntryManager();

    TSManager* manager;

private:

};

#endif // ENTRYMANAGER_H
