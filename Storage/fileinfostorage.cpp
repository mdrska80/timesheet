#include "fileinfostorage.h"
#include "Common/entriesanalyzer.h"
#include "Storage/persistentstorage_xml.h"


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

    QStringList lst = IdentifyFiles("Data");

    int cnt = lst.size();
    for (int i = 0;i<cnt;i++)
    {
        EntryFileInfo *efi = ReadInfo(lst[i]);

        if (efi != NULL)
            infos.append(efi);
    }

}

EntryFileInfo* FileInfoStorage::ReadInfo(QString filename)
{
    EntryFileInfo* efi = new EntryFileInfo();

    PersistentStorage_XML storage;
    storage.ReadEntries("Data/"+filename);

    if (storage.entries.size() == 0)
    {
        efi->err.title = "No entries in file loaded, unknown format?";
        efi->isValid = false;
        return efi;
    }

    EntriesAnalyzer analyzer(&storage.entries);
    analyzer.Analyze();

    efi->filename = filename;
    efi->Process();

    efi->totalEntries = analyzer.entriesCnt;
    efi->totalWorkedHours = analyzer.workedHours;
    efi->isValid = true;

    return efi;
}

QStringList FileInfoStorage::IdentifyFiles(QString path)
{
    QStringList nameFilter("*.xml");
    QDir directory(path);
    QStringList txtFilesAndDirectories = directory.entryList(nameFilter);

    return txtFilesAndDirectories;
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

template<class T>
bool dereferencedLessThan(T * o1, T * o2) {
    return *o1 < *o2;
}

void FileInfoStorage::Sort()
{
    qSort(infos.begin(), infos.end(), dereferencedLessThan<EntryFileInfo>);
}
