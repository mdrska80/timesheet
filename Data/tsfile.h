#ifndef TSFILE_H
#define TSFILE_H

#include <QString>

class TSFile
{
public:
    TSFile();

    int year;
    int month;

    QString GetFileName();
    QString GetFileName(int month, int year);

};

#endif // TSFILE_H
