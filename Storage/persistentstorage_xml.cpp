#include <QDomDocument>
#include <QDebug>

#include "persistentstorage_xml.h"
#include "../Common/helper.h"
#include "../Common/tscore.h"

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
//    SaveCompanies("companies.xml");
//    SaveProjects("projects.xml");
    SaveTags("tags.xml");
    SaveEntries(TSCore::I().GetEntriesFile());

    qDebug() << "Saving data";
}

void PersistentStorage_XML::Load()
{
    QString companiesFile = "companies.xml";
    QString projectsFile = "projects.xml";
    QString tagsFile = "tags.xml";
    QString entriesFile = TSCore::I().GetEntriesFile();
    QString dochazkaFile = TSCore::I().GetDochazkaFile();

    ReadDochazka(dochazkaFile);
    ReadCompanies(companiesFile);
    ReadProjects(projectsFile);
    ReadEntries(entriesFile);
    ReadTags(tagsFile);

    qDebug() << "Loading data";
}

void PersistentStorage_XML::SaveEntries(QString filename, TSVersions ver)
{
    int max = entries.size();
    QString qs = "<Entries>\n";

    for(int i = 0;i<max;i++)
    {
        Entry* e = entries.at(i);
        qs.append(e->toXml(ver));
    }

    //finalize xml
    qs.append("</Entries>");

    QDate dt = QDate(TSCore::I().workingYear, TSCore::I().workingMonth,1);
    QDate dtThreshold = QDate(2014,1,1);
    if (dt >= dtThreshold)
    {
        Helper::write_file(filename, qs);
    }
}

void PersistentStorage_XML::SaveCompanies(QString filename)
{
    int max = companies.size();
    QString qs = "<Companies>\n";

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
    QString qs = "<Projects>\n";

    for(int i = 0;i<max;i++)
    {
        Project* e = projects.at(i);
        qs.append(e->toXml());
    }

    //finalize xml
    qs.append("</Projects>");
    Helper::write_file(filename, qs);
}

void PersistentStorage_XML::SaveTags(QString filename)
{
    int max = tags.size();
    QString qs = "<Tags>\n";

    for(int i = 0;i<max;i++)
    {
        Tag* e = tags.at(i);
        qs.append(e->toXml());
    }

    //finalize xml
    qs.append("</Tags>");
    Helper::write_file(filename, qs);
}

void PersistentStorage_XML::ReadDochazka(QString filename)
{
    QString content;
    if (Helper::read_file_into_str(filename, &content))
    {
        dochazka.Process(content);
    }
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

void PersistentStorage_XML::ReadTags(QString filename)
{
    CleanTags();

    QString content;
    if (Helper::read_file_into_str(filename, &content))
    {
        QDomDocument doc;
        doc.setContent(content);

        QDomNodeList list = doc.elementsByTagName("Tag");

        for (int x = 0; x < list.count(); x++)
        {
            QDomElement node = list.at(x).toElement();

            Tag *t = ReadTag(node);
            tags.append(t);
        }
    }
}

Entry* PersistentStorage_XML::ReadEntry(QDomElement node)
{
    TSVersions version = IdentifyFormat(node);
    Entry* e = new Entry();
    e->version = version;

    switch (version) {
    case TSVersion_QT:
        e->id = node.attribute("id");
        e->date = QDate::fromString(node.attribute("date"), "dd.MM.yyyy");
        e->from = QTime::fromString(node.attribute("from"), "hh:mm");
        e->to = QTime::fromString(node.attribute("to"), "hh:mm");
        e->company = FindCompanyByName(node.attribute("company"));

        e->title = node.firstChildElement("Title").text();
        e->description = node.firstChildElement("Description").text();
        break;
    case TSVersion_GTK_Autocont:
    {
        //e->id = node.attribute("id");
        e->date = QDate::fromString(node.attribute("Date"), "d.MM.yyyy");
        e->from = QTime::fromString(node.attribute("From"), "hh:mm");
        e->to = QTime::fromString(node.attribute("To"), "hh:mm");
        e->company = FindCompanyByName("Autocont");

        //this is correct Description to title
        e->title = node.firstChildElement("Description").text();
        break;
    }
    case TSVersion_NET:
    {
        //e->id = node.attribute("id");
        QString date = node.firstChildElement("Date").text().split("T")[0];
        e->date = QDate::fromString(date, "yyyy-MM-dd");

        QString timeFrom = node.firstChildElement("From").text().split("T")[1];
        e->from = QTime::fromString(timeFrom, "hh:mm:ss");

        QString timeTo = node.firstChildElement("To").text().split("T")[1];
        e->to = QTime::fromString(timeTo, "hh:mm:ss");

        e->company = FindCompanyByName("Unicorn");

        //this is correct Description to title
        e->title = node.firstChildElement("Description").text();
        e->description = node.firstChildElement("Commment").text();

        e->coll.insert("MainCategory", node.firstChildElement("MainCategory").text());
        e->coll.insert("SubCategory", node.firstChildElement("SubCategory").text());
        e->coll.insert("Comment", node.firstChildElement("Commment").text());
        e->coll.insert("Checked", node.firstChildElement("Checked").text());
        e->coll.insert("ConfirmedFor", node.firstChildElement("ConfirmedFor").text());

        break;
    }
    case TSVersion_NET_WPF_Ka:
    {
        //e->id = node.attribute("id");
        QString date = node.firstChildElement("Date").text().split("T")[0];
        e->date = QDate::fromString(date, "yyyy-MM-dd");

        QString timeFrom = node.firstChildElement("From").text().split("T")[1].left(8);
        e->from = QTime::fromString(timeFrom, "hh:mm:ss");

        QString timeTo = node.firstChildElement("To").text().split("T")[1].left(8);
        e->to = QTime::fromString(timeTo, "hh:mm:ss");

        e->company = FindCompanyByName("Ka");

        //this is correct Description to title
        e->title = node.firstChildElement("Description").text();
        e->description = node.firstChildElement("Commment").text();

        e->coll.insert("MainCategory", node.firstChildElement("MainCategory").text());
        e->coll.insert("SubCategory1", node.firstChildElement("SubCategory1").text());
        e->coll.insert("SubCategory2", node.firstChildElement("SubCategory2").text());
        e->coll.insert("DirectWork", node.firstChildElement("DirectWork").text());
        e->coll.insert("ZarazeniZaka", node.firstChildElement("ZarazeniZaka").text());
        e->coll.insert("PocetOsob", node.firstChildElement("PocetOsob").text());
        e->coll.insert("TskState", node.firstChildElement("TskState").text());
        e->coll.insert("Comment", node.firstChildElement("Commment").text());
        break;
    }
    default:
        break;
    }

    //read bustec time
    if (e!=NULL)
    {
        //bustecTime = Helper::GetSecsAshhmm(dochazka.GetDuration(e->date));
        int diff = dochazka.GetDuration(e->date) - (8.5*60*60);
        QString bustecDiff = "";

        if (diff < 0)
            bustecDiff = "<font color='red'></b>"+Helper::GetSecsAsMin(qAbs(diff))+"</b></font>";
        else
            bustecDiff = "<font color='green'><b>"+Helper::GetSecsAsMin(qAbs(diff))+"</b></font>";

        e->bustecDiff = bustecDiff;
    }

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
    p->from = QDate::fromString(node.attribute("from"), "dd.MM.yyyy");
    p->to = QDate::fromString(node.attribute("to"), "dd.MM.yyyy");
    p->description = node.firstChildElement("Description").text();

    return p;
}

Tag* PersistentStorage_XML::ReadTag(QDomElement node)
{
    Tag* p = new Tag();

    p->code = node.attribute("code");
    p->color = node.attribute("color");

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
    filteredEntries.clear();
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

void PersistentStorage_XML::CleanTags()
{
    int cnt = tags.size();

    for (int i = 0;i<cnt;i++)
    {
        delete tags.at(i);
    }
    tags.clear();
}

QList<Entry*> PersistentStorage_XML::find(QString qs)
{
    QList<Entry*> lst;
    int cnt = entries.size();

    for (int i = 0;i<cnt;i++)
    {
        Entry *e = entries[i];
        qs = qs.toLower();

        if (e->title.toLower().contains(qs) || e->description.toLower().contains(qs))
            lst.append(e);
    }

    return lst;
}

TSVersions PersistentStorage_XML::IdentifyFormat(QDomElement &node)
{
    if (!node.attribute("date").isNull())
        return TSVersion_QT;

    if (!node.attribute("Date").isNull())
        return TSVersion_GTK_Autocont;

    if (!node.firstChildElement("Date").isNull() && !node.firstChildElement("SubCategory1").isNull())
        return TSVersion_NET_WPF_Ka;

    if (!node.firstChildElement("Date").isNull())
        return TSVersion_NET;

    return TSVersion_NET;
}

QList<float> PersistentStorage_XML::GetSpectrum()
{
    QList<float> list;

    QDate CurrentDate(TSCore::I().workingYear,TSCore::I().workingMonth, 1);
    int maxDays = GetMaxDay();// CurrentDate.daysInMonth();

    for(int i = 1; i<=maxDays; i++)
    {
        QList<Entry*> eries = GetEntriesForDay(i);
        int totalSecs = GetMassDuration(eries);
        int fullDaySecs = 10*60*60;

        float f =((float)totalSecs/((float)fullDaySecs/100))/100;

        //list << 0.1 << 0.9;
        list << f;
        //list << 0.1 << 0.4;
        //list << 0.5 << 0.5;
    }

    for(int i = 1; i<=maxDays; i++)
    {
        //not using fade...
        list << 0;
    }


    return list;
}

int PersistentStorage_XML::GetMaxDay()
{
    int maxday = 0;
    int cnt = entries.size();
    for(int i = 0;i<cnt;i++)
    {
        Entry *e = entries.at(i);
        if (maxday <= e->date.day())
            maxday = e->date.day();
    }

    // 0 is bad...
    if (maxday==0)
        maxday = 21;

    return maxday;
}

int PersistentStorage_XML::GetMassDuration(QList<Entry*> &entries)
{
    int secs =  0;
    int cnt = entries.size();

    for(int i = 0;i<cnt;i++)
    {
        secs += entries.at(i)->GetDuration();
    }

    return secs;
}

QList<Entry*> PersistentStorage_XML::GetEntriesForDay(int day)
{
    QList<Entry*> x;

    int cnt = entries.size();

    for (int i = 0;i<cnt;i++)
    {
        Entry* e = entries.at(i);

        if (e->date.day() == day)
            x.append(e);
    }

    return x;
}

QString PersistentStorage_XML::ExtractTitlesFromEntries(QList<Entry*> &entries)
{
    QString s = "";

    int cnt = entries.size();

    for (int i = 0;i<cnt;i++)
    {
        Entry* e = entries.at(i);
        s += "- "+e->title+"<br/>";
    }

    return s;
}
