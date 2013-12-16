#ifndef COMPANY_H
#define COMPANY_H

#include <QString>
#include <QtCore>

class Company
{
public:
    Company();

    QString Name;
    QString Description;

    QString Url;

    QDate From;
    QDate To;

};

#endif // COMPANY_H
