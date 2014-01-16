#include "dbmanager.h"

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>

DBManager::DBManager(TSManager* mgr)
{
    manager = mgr;
}

QList<Entry*> *DBManager::GetAllEntries()
{
    return NULL;
}

QString DBManager::CheckDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3");

    db.setHostName("localhost");
    db.setDatabaseName("timesheetdb");
    db.setUserName("ts");
    db.setPassword("Anub1s");

    if (db.open())
    {
        db.close();
        return "";
    }
    else
    {
        return db.lastError().text();
    }
}
