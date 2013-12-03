#ifndef TSPROJECTMANAGER_H
#define TSPROJECTMANAGER_H

#include <QHash>
#include <QSettings>
#include "Data/tsproject.h"

class TSProjectManager
{
public:
    TSProjectManager();
    ~TSProjectManager();

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

    QSettings* settings;
};

#endif // TSPROJECTMANAGER_H
