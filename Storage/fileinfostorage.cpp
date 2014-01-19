#include "fileinfostorage.h"

FileInfoStorage::FileInfoStorage()
{
}

FileInfoStorage::~FileInfoStorage()
{
    CleanInfos();
}

void FileInfoStorage::Load()
{
    ReadInfos();
}

void FileInfoStorage::ReadInfos()
{
    CleanInfos();
}

EntryFileInfo* FileInfoStorage::ReadInfo()
{
    return NULL;
}

QStringList FileInfoStorage::IdentifyFiles()
{
    QStringList lst;
    return lst;
}

void FileInfoStorage::CleanInfos()
{
    int cnt = infos.size();

    for (int i = 0;i<cnt;i++)
    {
        delete infos.at(i);
    }

    infos.clear();
}
