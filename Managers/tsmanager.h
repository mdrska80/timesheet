#ifndef TSMANAGER_H
#define TSMANAGER_H

#include "tsprojectmanager.h"
#include "compmanager.h"
#include "entrymanager.h"
#include "Data/tsfile.h"

class TSProjectManager;
class CompManager;
class EntryManager;

// Manager of managers.
class TSManager
{
public:
    TSManager();
    ~TSManager();

    TSProjectManager* projects;
    CompManager* computations;
    EntryManager* entries;

    TSFile* tsfile;

    void Init(void);

private:

};

#endif // TSMANAGER_H
