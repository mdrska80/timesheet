#ifndef BUSTECENTRY_H
#define BUSTECENTRY_H

#include <QtCore>

class BustecEntry
{
public:
    BustecEntry();

    //Datum a čas	Akce	Název akce	Terminál	Příjmení	Jméno

    // Datum záznamu
    QDate Date;

    // Čas záznamu
    QTime Time;

    // Název akce,
    // 1 - PRICHOD DO PRACE
    // 2 - ODCHOD
    // ...
    // 16 - SLUZEBNI POCHUZKA
    int Action;

    // Název akce
    QString ActionName;

    // terminal
    int Terminal;

    // Příjmení
    QString Surname;

    // Jméno
    QString Name;
};

#endif // BUSTECENTRY_H
