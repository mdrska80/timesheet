#include "entriesanalyzer.h"

EntriesAnalyzer::EntriesAnalyzer(QList<Entry*>* entries)
{
    sourceEntries = entries;
}

void EntriesAnalyzer::Analyze()
{
    entriesCnt = sourceEntries->size();
}
