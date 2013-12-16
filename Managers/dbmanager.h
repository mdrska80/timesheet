#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QList>
#include "Data/entry.h"
#include "Managers/tsmanager.h"

class DBManager
{
public:
    DBManager(TSManager* mgr);
    TSManager* manager;

    // method will return all possible entries
    QList<Entry*> *GetAllEntries();

    // methods will return filtered entries
    QList<Entry*> *GetEntries(int year);
    QList<Entry*> *GetEntries(int year, int month);
    QList<Entry*> *GetEntries(int year, int month, int day);

    // helper filtering methods
    QList<Entry*> *GetYesterDayEntries();
    QList<Entry*> *GetToDayEntries();

    // Parenting
    Entry* GetParentEntry(Entry* e);

    // CRUD
    bool CreateEntry(Entry* e);
    bool UpdateEntry(Entry* e);
    bool DeleteEntry(Entry* e);
    bool DeleteEntry(int id);

    // test
    bool CheckDb();
};

#endif // DBMANAGER_H
