#ifndef TSCORE_H
#define TSCORE_H

#include <QtCore>
#include "../Data/company.h"
#include "../Data/project.h"
#include "../Data/aggregatedentry.h"

#include "../Storage/fileinfostorage.h"

class TSCore
{
public:
    TSCore();

    // what year and month we are currently working in...
    int workingYear;
    int workingMonth;
    bool needReload;

    QString dataDir;

    QString GetEntriesFile();

    // singleton stuff
    static TSCore& I()
    {
        static TSCore instance; // Guaranteed to be destroyed.
                                // Instantiated on first use.
        return instance;
    }


    Company* GetCompany(QDate dt);
    Project* GetProject(QDate dt);

    void MoveForward();
    void MoveBackward();
    void MoveToPresent();

    QString GetVersion();


    QList<Company*> companies;
    QList<Project*> projects;

    FileInfoStorage fiStorage;

    QHash<int, AggregatedEntry*> agregatedEntries;
    void RecalculateAggregatedEntries(QList<Entry*>* entries);

private:
    TSCore(TSCore const&);              // Don't Implement
    void operator=(TSCore const&); // Don't implement
};

#endif // TSCORE_H
