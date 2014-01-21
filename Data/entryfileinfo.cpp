#include "entryfileinfo.h"
#include "Common/helper.h"

EntryFileInfo::EntryFileInfo()
{
    isMissing = false;
    workedHours = 0;
    entryCount = 0;
    pl_selected = false;
}

bool EntryFileInfo::operator<(const EntryFileInfo &event)
{
    return date<event.date;
}

