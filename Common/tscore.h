#ifndef TSCORE_H
#define TSCORE_H

#include <QtCore>

class TSCore
{
public:
    TSCore();

    // what year and month we are currently working in...
    int workingYear;
    int workingMonth;
    bool needReload;

    QString dataDir;

    QString GetEntriesFile();

    // singleton stuff
    static TSCore& I()
    {
        static TSCore instance; // Guaranteed to be destroyed.
                                // Instantiated on first use.
        return instance;
    }

private:
    TSCore(TSCore const&);              // Don't Implement
    void operator=(TSCore const&); // Don't implement

};

#endif // TSCORE_H
