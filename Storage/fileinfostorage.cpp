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
    CheckAllFilesExistence();

    isLoaded = true;
    needRefresh = false;
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
    efi->isValid = true;

    PersistentStorage_XML storage;
    storage.ReadEntries("Data/"+filename);

    if (storage.entries.size() == 0)
    {
        efi->err.title = "No entries in file loaded, unknown format?";
        efi->isValid = false;
        return efi;
    }

    efi->filename = filename;

    EntriesAnalyzer analyzer(&storage.entries, efi);
    analyzer.Analyze();

    int cnt = efi->titles.size();
    for (int i=0;i<cnt;i++)
    {
        titles.append(efi->titles[i]);
    }

    return efi;
}

QStringList FileInfoStorage::IdentifyFiles(QString path)
{
    QStringList nameFilter("*.xml");
    QDir directory(path);
    QStringList txtFilesAndDirectories = directory.entryList(nameFilter);

    return txtFilesAndDirectories;
}

void FileInfoStorage::CheckAllFilesExistence()
{
    // this could be static
    int startYear = 2004;
    int startMonth = 2-1;

    int curMonth = startMonth;
    int curYear = startYear;
    bool scan = true;

    //look for each month till start
    while(scan)
    {
        int noOfInfos = infos.size();
        bool found = false;
        curMonth++;
        if (curMonth == 13)
        {
            curMonth = 1;
            curYear++;
        }

        for (int i = 0; i< noOfInfos; i++)
        {
            EntryFileInfo *fi = infos[i];

            if (fi->date.month() == curMonth && fi->date.year() == curYear)
                found = true;
        }

        if (!found)
        {
            EntryFileInfo *fi = new EntryFileInfo();
            fi->date.setDate(curYear, curMonth, 1);
            fi->isMissing = true;
            infos.append(fi);
        }

        if (curMonth == QDate::currentDate().month() && curYear == QDate::currentDate().year())
            scan = false;

    }

    Sort();

}

void FileInfoStorage::CleanInfos()
{
    int cnt = infos.size();

    for (int i = 0;i<cnt;i++)
    {
        delete infos.at(i);
    }

    infos.clear();
    filteredInfos.clear();
}

template<class T>
bool dereferencedLessThan(T * o1, T * o2) {
    return *o1 < *o2;
}

void FileInfoStorage::Sort()
{
    qSort(infos.begin(), infos.end(), dereferencedLessThan<EntryFileInfo>);
}

QList<EntryFileInfo*> FileInfoStorage::find(QString qs)
{
    QList<EntryFileInfo*> lst;
    int cnt = infos.size();

    for (int i = 0;i<cnt;i++)
    {
        EntryFileInfo* efi = infos[i];
        int cntTitles = efi->titles.size();

        for(int j=0;j<cntTitles;j++)
        {
            if (efi->titles[j].contains(qs))
            {
                lst.append(efi);
                break;
            }
        }
    }

    return lst;
}
