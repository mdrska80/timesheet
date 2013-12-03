#include "tsprojectmanager.h"
#include <QSettings>
#include <QtCore>

TSProjectManager::TSProjectManager(TSManager* mgr)
{
    //store reference
    manager = mgr;

    tspColl = new QHash<QString, TSProject*>();
    InitConfig();
}

TSProjectManager::~TSProjectManager()
{
    QHash<QString, TSProject*>::iterator i;
    for (i = tspColl->begin(); i != tspColl->end(); ++i)
    {
        TSProject* proj = i.value();
        delete proj;
    }

    // delete collection
    delete tspColl;
    delete settings;
}

bool TSProjectManager::CheckUniqness(QString uniqueId)
{
    if (tspColl->contains(uniqueId))
        return false; // we found it -- so it is not unique...

    return true;
}

TSProject* TSProjectManager::GetProject(QString uniqueId)
{
    if (tspColl->contains(uniqueId))
        return tspColl->value(uniqueId);

    // we found nothing, return what we found :)
    return NULL;
}

TSProject* TSProjectManager::CreateNewProject(QString uniqueId)
{
    if (!CheckUniqness(uniqueId))
        return NULL;

    TSProject* project = new TSProject();
    project->id = uniqueId;

    return project;
}


void TSProjectManager::Load()
{
    // read filename from config file
    QString filename = settings->value("files/projectsFile", "").toString();
    Load(filename);
}

void TSProjectManager::Load(QString filename)
{
}

void TSProjectManager::Save()
{
    // read filename from config file
    QString filename = settings->value("files/projectsFile", "").toString();
    Save(filename);
}

void TSProjectManager::Save(QString filename)
{

}

void TSProjectManager::InitConfig()
{
    // if not null we do not need any initialization :)
    settings = new QSettings(QString("config.ini"), QSettings::IniFormat);
}


