#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include <QtCore>

class ErrorMessage
{
public:
    ErrorMessage();

    QString title;
    QString description;
    QString detail;
};

#endif // ERRORMESSAGE_H
