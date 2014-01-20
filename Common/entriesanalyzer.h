#ifndef ENTRIESANALYZER_H
#define ENTRIESANALYZER_H

#include <QList>
#include "Data/entry.h"

class EntriesAnalyzer
{
public:
    EntriesAnalyzer(QList<Entry*>* entries);

    // analysis functions
    void Analyze();

    // result variables
    int entriesCnt;
    int workedHours;
private:
    QList<Entry*>* sourceEntries;
    //
};

#endif // ENTRIESANALYZER_H
