#ifndef TAG_H
#define TAG_H

#include <QtCore>

class Tag
{
public:
    Tag();

    // Name of the tag which will be displayed...
    QString displayName;

    // id/code of the tag
    QString code;

    // color of the tag.
    QColor color;

    // tag can have parent
    Tag* parent;

    // code of the parent tag
    QString parentCode;

    //Pr.:
    // displayName = Okna, Firma
    // code = OKNA, FIRMA
    // color = ...
    // parent none...
};

#endif // TAG_H
