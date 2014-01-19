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
    int totalEntries;

    int totalWorkedHours;
    CompaniesList company;

    bool isValid;
    ErrorMessage err;

    //system
    bool pl_selected;

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
