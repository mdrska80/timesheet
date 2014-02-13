#ifndef TAG_H
#define TAG_H

#include <QtCore>
#include <QColor>

class Tag
{
public:
    Tag();

    // id/code of the tag
    QString code;

    // color of the tag.
    QColor color;

    QString toXml();

};

#endif // TAG_H
