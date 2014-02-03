#ifndef TSMANAGER_H
#define TSMANAGER_H

#include "compmanager.h"
#include "entrymanager.h"
#include "dbmanager.h"
#include "../Data/tsfile.h"

class TSProjectManager;
class CompManager;
class EntryManager;
class DBManager;

// Manager of managers.
class TSManager
{
public:
    TSManager();
    ~TSManager();

    CompManager* computations;
    EntryManager* entries;
    DBManager* db;

    TSFile* tsfile;

    void Init(void);

private:

};

#endif // TSMANAGER_H
