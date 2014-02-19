#ifndef FILEINFOSTORAGE_H
#define FILEINFOSTORAGE_H

#include <QtCore>
#include "../Data/entryfileinfo.h"
#include "../Data/company.h"

class FileInfoStorage
{
public:
    FileInfoStorage();
    ~FileInfoStorage();

    void Load(bool onlyActiveCompany);
    void ReadInfos(QDate start = QDate(2000,01,01));

    EntryFileInfo* ReadInfo(QString filename);
    void CleanInfos();

    QStringList IdentifyFiles(QString path);
    void Sort();
    void CheckAllFilesExistence();
    Company* GetActiveCompany();

    QList<EntryFileInfo*> infos;
    QList<EntryFileInfo*> filteredInfos;
    QList<EntryFileInfo*> find(QString qs);

    QStringList titles;

    //status
    bool isLoaded;
    bool needRefresh;
};

#endif // FILEINFOSTORAGE_H
