#include "tsmanager.h"

TSManager::TSManager()
{
}

TSManager::~TSManager()
{
    delete projects;
    delete computations;
    delete entries;
}

void TSManager::Init(void)
{
    projects = new TSProjectManager();
    computations = new CompManager();
    entries = new EntryManager() ;
}



