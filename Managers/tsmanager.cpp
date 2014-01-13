#include "tsmanager.h"

TSManager::TSManager()
{
    Init();
}

TSManager::~TSManager()
{
    delete computations;
    delete entries;
    delete tsfile;
    delete db;
}

void TSManager::Init(void)
{
    computations = new CompManager(this);
    entries = new EntryManager(this) ;
    db = new DBManager(this);
    tsfile = new TSFile();
}



