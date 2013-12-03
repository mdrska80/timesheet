#ifndef TSPROJECTMANAGER_H
#define TSPROJECTMANAGER_H

#include <QHash>
#include <QSettings>
#include "Data/tsproject.h"
#include "Managers/tsmanager.h"

class TSManager;

class TSProjectManager
{
public:
    TSProjectManager(TSManager* mgr);
    ~TSProjectManager();

    TSManager* manager;
    QSettings* settings;

    bool CheckUniqness(QString uniqueId);
    TSProject* GetProject(QString uniqueId);
    TSProject* CreateNewProject(QString uniqueId);

    // Crud part
    void Load();
    void Save();

    void InitConfig();


private:
    QHash<QString, TSProject*> *tspColl;
    void Load(QString filename);
    void Save(QString filename);
};

#endif // TSPROJECTMANAGER_H
