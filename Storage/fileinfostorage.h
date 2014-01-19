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

    EntryFileInfo* ReadInfo();
    void CleanInfos();

    QStringList IdentifyFiles();


    QList<EntryFileInfo*> infos;
};

#endif // FILEINFOSTORAGE_H
