#include <QDomDocument>
#include <QDebug>

#include "persistentstorage_xml.h"
#include "Common/helper.h"

PersistentStorage_XML::PersistentStorage_XML()
{
    companies = new QList<Company*>();
    entries = new QList<Entry*>();
}

PersistentStorage_XML::~PersistentStorage_XML()
{
    CleanEntries();
    CleanCompanies();

    delete companies;
    delete entries;
}


void PersistentStorage_XML::SaveEntries(QString filename)
{
    int max = entries->size();
    QString qs = "<Entries>\r\n";

    for(int i = 0;i<max;i++)
    {
        Entry* e = entries->at(i);
        qs.append(e->toXml());
    }

    //finalize xml
    qs.append("</Entries>");
    Helper::write_file(filename, qs);
}

void PersistentStorage_XML::SaveCompanies(QString filename)
{
    int max = companies->size();
    QString qs = "<Companies>\r\n";

    for(int i = 0;i<max;i++)
    {
        Company* e = companies->at(i);
        qs.append(e->toXml());
    }

    //finalize xml
    qs.append("</Companies>");
    Helper::write_file(filename, qs);
}


QList<Entry*>* PersistentStorage_XML::Load()
{
    QString companiesFile = "companies.xml";
    QString entriesFile = "test.xml";

    ReadCompanies(companiesFile);
    ReadEntries(entriesFile);
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
            entries->append(e);
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
            companies->append(c);
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

Company* PersistentStorage_XML::FindCompanyByName(QString name)
{
    int companiesCnt = companies->size();

    for (int i = 0;i<companiesCnt;i++)
    {
        if (companies->at(i)->name == name)
            return companies->at(i);
    }

    return 0;
}

void PersistentStorage_XML::CleanEntries()
{
    int cnt = entries->size();

    for (int i = 0;i<cnt;i++)
    {
        delete entries->at(i);
    }

    entries->clear();
}

void PersistentStorage_XML::CleanCompanies()
{
    int cnt = companies->size();

    for (int i = 0;i<cnt;i++)
    {
        delete companies->at(i);
    }
    companies->clear();

}

