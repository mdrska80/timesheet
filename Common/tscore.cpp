#include "tscore.h"

TSCore::TSCore()
{
    dataDir = "Data";
    workingMonth = QDate::currentDate().month();
    workingYear = QDate::currentDate().year();
    needReload = false;

    fiStorage = FileInfoStorage();
}

QString TSCore::GetEntriesFile()
{
    return QString("%1/%2-%3.xml").arg(dataDir).arg(workingYear).arg(workingMonth);
}

Company* TSCore::GetCompany(QDate dt)
{
    int cnt = companies.size();

    for (int i = 0; i<cnt; i++)
    {
        Company* c = companies[i];
        if (dt >= c->from && dt <= c->to)
            return c;
    }

    return NULL;
}

Project* TSCore::GetProject(QDate dt)
{
    int cnt = projects.size();

    for (int i = 0; i<cnt; i++)
    {
        Project* c = projects[i];
        if (dt >= c->from && dt <= c->to)
            return c;
    }

    return NULL;
}

void TSCore::MoveForward()
{
    workingMonth++;

    if (workingMonth == 13)
    {
        workingMonth = 1;
        workingYear++;
    }
}

void TSCore::MoveBackward()
{
    workingMonth--;

    if (workingMonth == 0)
    {
        workingMonth = 12;
        workingYear--;
    }
}


void TSCore::MoveToPresent()
{
    workingMonth = QDate::currentDate().month();
    workingYear = QDate::currentDate().year();
}



