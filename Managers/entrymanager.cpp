#include "entrymanager.h"

EntryManager::EntryManager(TSManager* mgr)
{
    //store reference
    manager = mgr;

}

EntryManager::~EntryManager()
{
    // delete list contents
    QList<Entry*>::iterator i;
    for (i = entries->begin(); i != entries->end(); ++i)
    {
        Entry* e = *i;
        delete e;
    }
}

void EntryManager::Load()
{
    // read filename from config file
    QString filename = manager->projects->settings->value("files/projectsFile", "").toString();
    Load(filename);
}

void EntryManager::Load(QString filename)
{
}
