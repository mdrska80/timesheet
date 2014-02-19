#ifndef TSCORE_H
#define TSCORE_H

#include <QtCore>
#include "../Data/company.h"
#include "../Data/project.h"
#include "../Data/aggregatedentry.h"

#include "../Storage/fileinfostorage.h"
#include "../Storage/persistentstorage_xml.h"

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
    Tag* GetTag(QString name);

    void MoveForward();
    void MoveBackward();
    void MoveToPresent();

    QString GetVersion();
    QDate GetDateFromFilename(QString filename);


    FileInfoStorage fiStorage;
    PersistentStorage_XML entriesStorage;

    QHash<int, AggregatedEntry*> agregatedEntries;
    void RecalculateAggregatedEntries(QList<Entry*>* entries);

private:
    TSCore(TSCore const&);              // Don't Implement
    void operator=(TSCore const&); // Don't implement
};

#endif // TSCORE_H
