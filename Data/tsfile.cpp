#include "tsfile.h"
#include <QDate>

TSFile::TSFile()
{
    //get current month and year.
    QDate now = QDate::currentDate();
    month = now.month();
    year = now.year();
}

QString TSFile::GetFileName(int month, int year)
{
    // A hint:

    // fieldWidth = 5 (4 digits + decimal point)
    // format = 'f'
    // precision = 2 (number of digits after the decimal point)
    // fillChar = '0'
    QString result = QString("Data/%1_%2.xml").arg(month,2,'f',0, '0').arg(year);

    return result;
}

QString TSFile::GetFileName()
{
    return GetFileName(month, year);
}
