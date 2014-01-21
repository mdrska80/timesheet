#ifndef PERSISTENTSTORAGE_XML_H
#define PERSISTENTSTORAGE_XML_H

#include <QList>
#include <QDomDocument>

#include "Data/entry.h"
#include "Data/company.h"
#include "Data/project.h"
#include "Common/enums.h"

class PersistentStorage_XML
{
public:
    PersistentStorage_XML();
    ~PersistentStorage_XML();

    void Load();
    void Save(void);
    void SaveEntries(QString filename, TSVersions ver = TSVersion_QT);
    void SaveCompanies(QString filename);
    void SaveProjects(QString filename);

    void ReadEntries(QString filename);
    void ReadCompanies(QString filename);
    void ReadProjects(QString filename);

    Entry* ReadEntry(QDomElement node);
    Company* ReadCompany(QDomElement node);
    Project* ReadProject(QDomElement node);

    //helper methods
    Company* FindCompanyByName(QString name);
    Project* FindProjectByName(QString name);

    void CleanEntries();
    void CleanCompanies();
    void CleanProjects();

    void ApplyFilter(FilterTypes ft, bool highlightTodayEntries);
    void HandleTodayHighlight(Entry *e, bool highlightTodayEntries);

    TSVersions IdentifyFormat(QDomElement &node);


private:
    void Sort();

public:
    QList<Entry*> entries;
    QList<Company*> companies;
    QList<Project*> projects;

    QList<Entry*> filteredEntries;

};

#endif // PERSISTENTSTORAGE_XML_H
