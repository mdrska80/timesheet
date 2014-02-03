#ifndef ENTRIESANALYZER_H
#define ENTRIESANALYZER_H

#include <QList>
#include "../Data/entry.h"
#include "../Data/entryfileinfo.h"

class EntriesAnalyzer
{
public:
    EntriesAnalyzer(QList<Entry*>* entries, EntryFileInfo* efi);

    // analysis functions
    void Analyze();

    // result variables
    EntryFileInfo* _efi;
    //int entriesCnt;
    //double workedHours;
    //double workingHours;
private:
    QList<Entry*>* sourceEntries;
    int mnth;
    int yr;

    int CalculateWorkingDays(int month, int year);
    void GetDateFromFilename();

    //
};

#endif // ENTRIESANALYZER_H
