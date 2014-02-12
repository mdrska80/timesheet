#ifndef ATTACHMENT_H
#define ATTACHMENT_H

#include <QUuid>
#include <QIcon>

class Attachment
{
public:
    Attachment();
    Attachment(QString uuid);

    // Folder name, entry can have multiple attachments
    QString _uuid;

    // Name of the attachment, filename
    QString name;

    //methods
    void PrepareFolder();
    QIcon FetchIcon();
    void CopyLocal();
};

#endif // ATTACHMENT_H
