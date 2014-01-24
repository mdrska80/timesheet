#ifndef FILTERBASE_H
#define FILTERBASE_H

#include <QtCore>
#include "Data/entry.h"

class FilterBase
{
public:
    FilterBase();
    virtual ~FilterBase(){}

    //Filter name
    QString name;
    QString code;

    bool highlightTodayEntries;

    virtual QList<Entry*> apply(QList<Entry*> entries)=0;

protected:
    // helper methods
    void HandleTodayHighlight(Entry *e);
    void Sort(QList<Entry*>* filtered);


signals:

public slots:

};

#endif // FILTERBASE_H
