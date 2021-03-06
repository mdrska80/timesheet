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

QString TSCore::GetDochazkaFile()
{
    return QString("%1/bustec/%2-%3.txt").arg(dataDir).arg(workingYear).arg(workingMonth);
}

Company* TSCore::GetCompany(QDate dt)
{
    int cnt = entriesStorage.companies.size();

    for (int i = 0; i<cnt; i++)
    {
        Company* c = entriesStorage.companies[i];
        if (dt >= c->from && dt <= c->to)
            return c;
    }

    return NULL;
}

Project* TSCore::GetProject(QDate dt = QDate(2000,01,01))
{
    int cnt = entriesStorage.projects.size();

    for (int i = 0; i<cnt; i++)
    {
        Project* c = entriesStorage.projects[i];
        if (dt >= c->from && dt <= c->to)
            return c;
    }

    return NULL;
}

Tag* TSCore::GetTag(QString name)
{
    int cnt = entriesStorage.tags.size();

    for (int i = 0; i<cnt; i++)
    {
        Tag* t = entriesStorage.tags[i];

        if (t->code == name)
            return t;
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

QDate TSCore::GetDateFromFilename(QString filename)
{
    // this is how filename is created
    // QString("%1/%2-%3.xml").arg(dataDir).arg(workingYear).arg(workingMonth);
    filename = filename.replace(".xml","");
    QStringList lst = filename.split('-');

    if (lst.size() == 2)
    {
        QString strYear = lst[0];
        QString strMonth = lst[1];

        int year = strYear.toInt();
        int month = strMonth.toInt();

        return QDate(year, month, 1);
    }

    return QDate::currentDate();
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



