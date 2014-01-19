#ifndef COMPLETERTITLE_H
#define COMPLETERTITLE_H

#include <QCompleter>
#include "Common/enums.h"
#include "Storage/persistentstorage_xml.h"

class CompleterTitle : public QCompleter
{
    Q_OBJECT
public:
    explicit CompleterTitle(QObject *parent = 0);

    void ReloadCache();
    CompleterLoaderStates GetState();

private:
    void LoadAll();

    CompleterLoaderStates state;
    QStringList wordList;
    PersistentStorage_XML storage;


signals:

public slots:

};

#endif // COMPLETERTITLE_H
