#include "tsmanager.h"

TSManager::TSManager()
{
}

TSManager::~TSManager()
{
    delete projects;
    delete computations;
    delete entries;
    delete tsfile;
    delete db;
}

void TSManager::Init(void)
{
    projects = new TSProjectManager(this);
    computations = new CompManager(this);
    entries = new EntryManager(this) ;
    db = new DBManager(this);
    tsfile = new TSFile();
}



