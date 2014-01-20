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

    EntryFileInfo* i1 = new EntryFileInfo();
    i1->filename = "2004-5.xml";
    i1->totalEntries = 25;
    i1->totalWorkedHours = 160;
    i1->company = Unicorn;
    i1->isValid = true;
    //i1->Process();

    EntryFileInfo* i2 = new EntryFileInfo();
    i2->filename = "2004-6.xml";
    i2->totalEntries = 25;
    i2->totalWorkedHours = 160;
    i2->company = Unicorn;
    i2->isValid = false;

    EntryFileInfo* i3 = new EntryFileInfo();
    i3->filename = "2004-7.xml";
    i3->totalEntries = 25;
    i3->totalWorkedHours = 160;
    i3->company = Unicorn;
    i3->isValid = true;

    EntryFileInfo* i4 = new EntryFileInfo();
    i4->filename = "2004-8.xml";
    i4->totalEntries = 25;
    i4->totalWorkedHours = 160;
    i4->company = Unicorn;
    i4->isValid = true;

    infos.append(i1);
    infos.append(i2);
    infos.append(i3);
    infos.append(i4);

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
