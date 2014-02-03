#include "tscore.h"

TSCore::TSCore()
{
    dataDir = "Data";
    workingMonth = QDate::currentDate().month();
    workingYear = QDate::currentDate().year();
    needReload = false;

    fiStorage.isLoaded = false;
    fiStorage.needRefresh = true;
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

QString TSCore::GetVersion()
{
    return "7.0";
}

void TSCore::RecalculateAggregatedEntries(QList<Entry*>* entries)
{
    int maxAE = agregatedEntries.keys().size();
    for(int i = 0;i<maxAE;i++)
    {
        int key = agregatedEntries.keys().at(i);
        AggregatedEntry* ae = agregatedEntries[key];
        delete ae;
    }
    agregatedEntries.clear();


    int max = entries->size();
    for(int i = 0;i<max;i++)
    {
        Entry* e = entries->at(i);
        AggregatedEntry* ae = agregatedEntries[e->date.day()];

        if (ae == NULL)
            ae = new AggregatedEntry();

        ae->entries.append(e);
        ae->init();
    }
}



