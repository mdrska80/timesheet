#ifndef PERSISTENTSTORAGE_XML_H
#define PERSISTENTSTORAGE_XML_H

#include <QList>
#include <QDomDocument>

#include "../Data/entry.h"
#include "../Data/company.h"
#include "../Data/project.h"
#include "../Data/bustecdochazka.h"
#include "../Common/enums.h"

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
    void SaveTags(QString filename);

    void ReadEntries(QString filename);
    void ReadCompanies(QString filename);
    void ReadProjects(QString filename);
    void ReadTags(QString filename);
    void ReadDochazka(QString filename);

    Entry* ReadEntry(QDomElement node);
    Company* ReadCompany(QDomElement node);
    Project* ReadProject(QDomElement node);
    Tag* ReadTag(QDomElement node);

    //helper methods
    Company* FindCompanyByName(QString name);
    Project* FindProjectByName(QString name);

    void CleanEntries();
    void CleanCompanies();
    void CleanProjects();
    void CleanTags();

    QList<Entry*> find(QString qs);
    TSVersions IdentifyFormat(QDomElement &node);

    // spectrum code
    int GetMaxDay();
    QList<float> GetSpectrum();
    int GetMassDuration(QList<Entry*> &entries);
    QList<Entry*> GetEntriesForDay(int day);
    QString ExtractTitlesFromEntries(QList<Entry *> &entries);

    //helper metthods
    void GetFromToByDate(QDate date, QTime &from, QTime &to);
    QTime GetPrichod(QList<Entry*> lst);
    QTime GetOdchod(QList<Entry*> lst);



public:
    QList<Entry*> entries;
    QList<Company*> companies;
    QList<Project*> projects;
    QList<Tag*> tags;

    QList<Entry*> filteredEntries;
    BustecDochazka dochazka;

};

#endif // PERSISTENTSTORAGE_XML_H
