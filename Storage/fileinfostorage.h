#ifndef FILEINFOSTORAGE_H
#define FILEINFOSTORAGE_H

#include <QtCore>
#include "Data/entryfileinfo.h"

class FileInfoStorage
{
public:
    FileInfoStorage();
    ~FileInfoStorage();

    void Load();
    void ReadInfos();

    EntryFileInfo* ReadInfo(QString filename);
    void CleanInfos();

    QStringList IdentifyFiles(QString path);
    void Sort();
    void CheckAllFilesExistence();

    QList<EntryFileInfo*> infos;
    QList<EntryFileInfo*> filteredInfos;
    QList<EntryFileInfo*> find(QString qs);

    QStringList titles;

    //status
    bool isLoaded = false;
    bool needRefresh = false;
};

#endif // FILEINFOSTORAGE_H
