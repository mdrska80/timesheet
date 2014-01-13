#ifndef PERSISTENTSTORAGE_XML_H
#define PERSISTENTSTORAGE_XML_H

#include <QList>
#include <QDomDocument>

#include "Data/entry.h"
#include "Data/company.h"

class PersistentStorage_XML
{
public:
    PersistentStorage_XML();
    ~PersistentStorage_XML();

    QList<Entry*>* Load();
    void SaveEntries(QString filename);
    void SaveCompanies(QString filename);

    void ReadEntries(QString filename);
    void ReadCompanies(QString filename);

    Entry* ReadEntry(QDomElement node);
    Company* ReadCompany(QDomElement node);

    //helper methods
    Company* FindCompanyByName(QString name);
    void CleanEntries();
    void CleanCompanies();


    QList<Company*> *companies;
    QList<Entry*> *entries;

};

#endif // PERSISTENTSTORAGE_XML_H
