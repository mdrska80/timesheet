#include "tscore.h"

TSCore::TSCore()
{
    dataDir = "Data";
    workingMonth = QDate::currentDate().month();
    workingYear = QDate::currentDate().year();
}

QString TSCore::GetEntriesFile()
{
    return QString("%1/%2-%3.xml").arg(dataDir).arg(workingYear).arg(workingMonth);
}


