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

    QList<EntryFileInfo*> infos;
};

#endif // FILEINFOSTORAGE_H
