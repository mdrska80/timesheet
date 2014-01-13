#include "entrymanager.h"
#include <QDomDocument>

EntryManager::EntryManager(TSManager* mgr)
{
    //store reference
    manager = mgr;
}

EntryManager::~EntryManager()
{
}
