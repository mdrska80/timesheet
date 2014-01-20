#include "entryfileinfo.h"
#include "Common/helper.h"

EntryFileInfo::EntryFileInfo()
{
    pl_selected = false;
}

void EntryFileInfo::Process()
{
    QString qs = filename.replace(".xml", "");
    //try to get date
    QStringList lst = qs.split("-");

    if (lst.size() == 2)
    {
        int year = lst[0].toInt();
        int month = lst[1].toInt();

        date.setDate(year, month,1);
    }

    //based on date, pick up company
    company = Undefined;
}


bool EntryFileInfo::operator<(const EntryFileInfo &event)
{
    return date<event.date;
}

