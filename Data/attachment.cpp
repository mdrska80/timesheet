#include "attachment.h"


Attachment::Attachment()
{
    QUuid uuid = QUuid::createUuid();
    _uuid = uuid.toString();
}

Attachment::Attachment(QString uuid)
{
    _uuid = uuid;
}



