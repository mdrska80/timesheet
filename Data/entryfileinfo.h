#ifndef ENTRYFILEINFO_H
#define ENTRYFILEINFO_H

#include <QtCore>
#include "Common/enums.h"
#include "errormessage.h"

class EntryFileInfo
{
public:
    EntryFileInfo();

    QString filename;

    //system or processed
    bool            pl_selected;
    QString         raw_xml;

    QStringList     titles;
    QStringList     projects;
    QDate           date;
    CompaniesList   company;
    int             totalEntries;
    int             totalWorkedHours;
    bool            isValid;

    ErrorMessage    err;

    void Process();

    bool operator<(const EntryFileInfo *);
    bool operator<(const EntryFileInfo &);


    QVariant toVariant() const{

        QStringList list;
        return list;
    }

    static bool fromVariant(QVariant v, EntryFileInfo* md){

        QStringList list = v.toStringList();
        return true;
    }
};

#endif // ENTRYFILEINFO_H
