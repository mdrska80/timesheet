#include <QDomDocument>
#include <QDebug>

#include "persistentstorage_xml.h"
#include "Common/helper.h"
#include "Common/tscore.h"

PersistentStorage_XML::PersistentStorage_XML()
{
}

PersistentStorage_XML::~PersistentStorage_XML()
{
    CleanEntries();
    CleanCompanies();
    CleanProjects();
}

void PersistentStorage_XML::Save()
{
    SaveCompanies("companies.xml");
    SaveProjects("projects.xml");
    SaveEntries(TSCore::I().GetEntriesFile());
}

void PersistentStorage_XML::Load()
{
    QString companiesFile = "companies.xml";
    QString projectsFile = "projects.xml";
    QString entriesFile = TSCore::I().GetEntriesFile();

    ReadCompanies(companiesFile);
    ReadProjects(projectsFile);
    ReadEntries(entriesFile);

    //ApplyFilter(FilterType_Today);

    //return entries;
}

void PersistentStorage_XML::SaveEntries(QString filename)
{
    int max = entries.size();
    QString qs = "<Entries>\r\n";

    for(int i = 0;i<max;i++)
    {
        Entry* e = entries.at(i);
        qs.append(e->toXml());
    }

    //finalize xml
    qs.append("</Entries>");
    Helper::write_file(filename, qs);
}

void PersistentStorage_XML::SaveCompanies(QString filename)
{
    int max = companies.size();
    QString qs = "<Companies>\r\n";

    for(int i = 0;i<max;i++)
    {
        Company* e = companies.at(i);
        qs.append(e->toXml());
    }

    //finalize xml
    qs.append("</Companies>");
    Helper::write_file(filename, qs);
}

void PersistentStorage_XML::SaveProjects(QString filename)
{
    int max = projects.size();
    QString qs = "<Projects>\r\n";

    for(int i = 0;i<max;i++)
    {
        Project* e = projects.at(i);
        qs.append(e->toXml());
    }

    //finalize xml
    qs.append("</Projects>");
    Helper::write_file(filename, qs);
}

void PersistentStorage_XML::ReadEntries(QString filename)
{
    CleanEntries();

    QString content;
    if (Helper::read_file_into_str(filename, &content))
    {
        QDomDocument doc;
        doc.setContent(content);

        QDomNodeList list = doc.elementsByTagName("Entry");
        int cnt = list.count();

        for (int x = 0; x < cnt; x++)
        {
            QDomElement node = list.at(x).toElement();

            Entry *e = ReadEntry(node);
            entries.append(e);
        }
    }
}

void PersistentStorage_XML::ReadCompanies(QString filename)
{
    CleanCompanies();

    QString content;
    if (Helper::read_file_into_str(filename, &content))
    {
        QDomDocument doc;
        doc.setContent(content);

        QDomNodeList list = doc.elementsByTagName("Company");

        for (int x = 0; x < list.count(); x++)
        {
            QDomElement node = list.at(x).toElement();

            Company *c = ReadCompany(node);
            companies.append(c);
        }
    }
}

void PersistentStorage_XML::ReadProjects(QString filename)
{
    CleanProjects();

    QString content;
    if (Helper::read_file_into_str(filename, &content))
    {
        QDomDocument doc;
        doc.setContent(content);

        QDomNodeList list = doc.elementsByTagName("Project");

        for (int x = 0; x < list.count(); x++)
        {
            QDomElement node = list.at(x).toElement();

            Project *p = ReadProject(node);
            projects.append(p);
        }
    }
}

Entry* PersistentStorage_XML::ReadEntry(QDomElement node)
{
    Entry* e = new Entry();

    e->id = node.attribute("id");
    e->date = QDate::fromString(node.attribute("date"), "dd.MM.yyyy");
    e->from = QTime::fromString(node.attribute("from"), "hh:mm");
    e->to = QTime::fromString(node.attribute("to"), "hh:mm");
    e->company = FindCompanyByName(node.attribute("company"));

    e->title = node.firstChildElement("Title").text();
    e->description = node.firstChildElement("Description").text();

    return e;
}

Company* PersistentStorage_XML::ReadCompany(QDomElement node)
{
    Company* c = new Company();

    c->id = node.attribute("id");
    c->name = node.attribute("name");
    c->description = node.firstChildElement("Description").text();
    c->url = node.attribute("url");
    c->from = QDate::fromString(node.attribute("from"), "dd.MM.yyyy");
    c->to = QDate::fromString(node.attribute("to"), "dd.MM.yyyy");

    return c;
}

Project* PersistentStorage_XML::ReadProject(QDomElement node)
{
    Project* p = new Project();

    p->id = node.attribute("id");
    p->name = node.attribute("name");
    p->description = node.firstChildElement("Description").text();
    p->parent = FindProjectByName(node.attribute("company"));

    return p;
}

Company* PersistentStorage_XML::FindCompanyByName(QString name)
{
    int companiesCnt = companies.size();

    for (int i = 0;i<companiesCnt;i++)
    {
        if (companies.at(i)->name == name)
            return companies.at(i);
    }

    return 0;
}

Project* PersistentStorage_XML::FindProjectByName(QString name)
{
    int cnt = projects.size();

    for (int i = 0;i<cnt;i++)
    {
        if (projects.at(i)->name == name)
            return projects.at(i);
    }

    return 0;
}

void PersistentStorage_XML::CleanEntries()
{
    int cnt = entries.size();

    for (int i = 0;i<cnt;i++)
    {
        delete entries.at(i);
    }

    entries.clear();
}

void PersistentStorage_XML::CleanCompanies()
{
    int cnt = companies.size();

    for (int i = 0;i<cnt;i++)
    {
        delete companies.at(i);
    }
    companies.clear();
}

void PersistentStorage_XML::CleanProjects()
{
    int cnt = projects.size();

    for (int i = 0;i<cnt;i++)
    {
        delete projects.at(i);
    }
    projects.clear();
}

void PersistentStorage_XML::ApplyFilter(FilterTypes ft, bool highlightTodayEntries)
{
    filteredEntries.clear();
    int cnt = entries.size();

    switch (ft) {
    case FilterType_Valid:
        {
            for (int i = 0;i<cnt;i++)
            {
                Entry *e = entries.at(i);
                if (highlightTodayEntries)
                    e->pl_playing = e->date == QDate::currentDate();

                if (e->date.isValid() && e->from.isValid() && e->to.isValid())
                    filteredEntries.append(e);
            }
        }
        break;
    case FilterType_InValid:
        {
            for (int i = 0;i<cnt;i++)
            {
                Entry *e = entries.at(i);
                HandleTodayHighlight(e, highlightTodayEntries);

                if (!e->date.isValid() || !e->from.isValid() || !e->to.isValid())
                    filteredEntries.append(e);
            }
        }
        break;
    case FilterType_Today:
        {
            for (int i = 0;i<cnt;i++)
            {
                Entry *e = entries.at(i);
                HandleTodayHighlight(e, highlightTodayEntries);

                if (e->date == QDate::currentDate())
                    filteredEntries.append(e);
            }
        }
        break;
    case FilterType_Yesterday:
        {
            for (int i = 0;i<cnt;i++)
            {
                Entry *e = entries.at(i);
                HandleTodayHighlight(e, highlightTodayEntries);

                if (e->date == QDate::currentDate().addDays(-1))
                    filteredEntries.append(e);
            }
        }
        break;

    case FilterType_All:
        {
            for (int i = 0;i<cnt;i++)
            {
                Entry *e = entries.at(i);
                HandleTodayHighlight(e, highlightTodayEntries);

                filteredEntries.append(e);
            }
        }
        break;

    default:
        break;
    }

    Sort();
}

void PersistentStorage_XML::HandleTodayHighlight(Entry *e, bool highlightTodayEntries)
{
    if (highlightTodayEntries)
        e->pl_playing = e->date == QDate::currentDate();
    else
        e->pl_playing = false;
}

template<class T>
bool dereferencedLessThan(T * o1, T * o2) {
    return *o1 < *o2;
}


void PersistentStorage_XML::Sort()
{
    qSort(filteredEntries.begin(), filteredEntries.end(), dereferencedLessThan<Entry>);
}
