#ifndef TSMANAGER_H
#define TSMANAGER_H

#include "tsprojectmanager.h"
#include "compmanager.h"
#include "entrymanager.h"

// Manager of managers.
class TSManager
{
public:
    TSManager();
    ~TSManager();

    TSProjectManager* projects;
    CompManager* computations;
    EntryManager* entries;

    void Init(void);

private:

};

#endif // TSMANAGER_H
