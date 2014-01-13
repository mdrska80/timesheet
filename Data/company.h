#ifndef COMPANY_H
#define COMPANY_H

#include <QString>
#include <QtCore>

class Company
{
public:
    Company();

    // unique id of the company
    QString id;

    //name of the company
    QString name;

    // What this company does
    QString description;

    // main website
    QString url;

    // when do i begin to work for this company
    QDate from;

    // when do i stop to work for this company
    QDate to;

    //methods
    QString toXml();
};

#endif // COMPANY_H
