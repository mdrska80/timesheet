#ifndef PERSISTENTSTORAGE_XML_H
#define PERSISTENTSTORAGE_XML_H

#include <QList>
#include <QDomDocument>

#include "Data/entry.h"
#include "Data/company.h"
#include "Data/project.h"

class PersistentStorage_XML
{
public:
    PersistentStorage_XML();
    ~PersistentStorage_XML();

    QList<Entry*>* Load();
    void SaveEntries(QString filename);
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


    QList<Entry*> *entries;
    QList<Company*> *companies;
    QList<Project*> *projects;

};

#endif // PERSISTENTSTORAGE_XML_H
