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
    bool            pl_activeFile;

    QStringList     titles;
    QStringList     projects;
    QDate           date;
    CompaniesList   company;
    int             entryCount;
    double          workedHours;
    double          workingHours;
    bool            isValid;
    bool            isMissing;

    ErrorMessage    err;

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
