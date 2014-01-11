#include "entrymanager.h"
#include <QDomDocument>

EntryManager::EntryManager(TSManager* mgr)
{
    //store reference
    manager = mgr;
    entries = new QList<Entry*>();
}

EntryManager::~EntryManager()
{
    // delete list contents
    QList<Entry*>::iterator i;
    for (i = entries->begin(); i != entries->end(); ++i)
    {
        Entry* e = *i;
        delete e;
    }
}

void EntryManager::Load()
{
    // read filename from config file
    QString filename = manager->projects->settings->value("files/projectsFile", "").toString();
    Load(filename);
}

void EntryManager::Load(QString filename)
{
//    QString xmlText = "nejake xml zde...";
  //  QDomDocument doc;
    //doc.setContent(xmlText);
//    QDomNodeList list=doc.elementsByName("string");
  //  QString helloWorld=list.at(0).toElement().text();
}
