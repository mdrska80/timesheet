#ifndef ENTRYMANAGER_H
#define ENTRYMANAGER_H

#include <QList>
#include "Data/entry.h"
#include "Managers/tsmanager.h"

class TSManager;

//all entry logic is handled here
class EntryManager
{
public:
    EntryManager(TSManager* mgr);
    ~EntryManager();

    TSManager* manager;

    // Crud part
    void Load();
    void Save();

private:
    QList<Entry*> *entries;

    void Load(QString filename);
    void Save(QString filename);
};

#endif // ENTRYMANAGER_H
