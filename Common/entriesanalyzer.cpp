#include "entriesanalyzer.h"

EntriesAnalyzer::EntriesAnalyzer(QList<Entry*>* entries, EntryFileInfo* efi)
{
    sourceEntries = entries;
    _efi = efi;
}

void EntriesAnalyzer::Analyze()
{
    GetDateFromFilename();
    yr = _efi->date.year();
    mnth = _efi->date.month();

    _efi->entryCount = sourceEntries->size();

    long tTotal = 0;
    for(int i =0;i<_efi->entryCount;i++)
    {
        Entry *e = sourceEntries->at(i);
        int seconds = e->GetDuration();
        tTotal += seconds;

        if (!_efi->titles.contains(e->title))
            _efi->titles.append(e->title);
    }

    _efi->workedHours = (double)tTotal/(double)3600;
    _efi->workingHours = CalculateWorkingDays(mnth, yr)*8;

    if (_efi->workedHours < _efi->workingHours)
        _efi->isValid = false;
}

int EntriesAnalyzer::CalculateWorkingDays(int month, int year)
{
    QDate CurrentDate = QDate(year, month, 1);// QDate::currentDate();
    int DaysInMonth = CurrentDate.daysInMonth();
    QDate FirstDayOfMonth = CurrentDate;
    FirstDayOfMonth.setDate(CurrentDate.year(), CurrentDate.month(), 1);


    int nonWDays = 0;
    for (int i =1;i<=DaysInMonth;i++)
    {
        QDate d = QDate(year, month, i);
        int dow = d.dayOfWeek();

        if (dow == 6 || dow == 7)
        nonWDays++;
    }

    return DaysInMonth - nonWDays;
}

void EntriesAnalyzer::GetDateFromFilename()
{
    QString qs = _efi->filename.replace(".xml", "");
    //try to get date
    QStringList lst = qs.split("-");

    if (lst.size() == 2)
    {
        int year = lst[0].toInt();
        int month = lst[1].toInt();

        _efi->date.setDate(year, month,1);
    }

    //based on date, pick up company
    _efi->company = Undefined;
}
