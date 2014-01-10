#ifndef GUI_ENTRYENTRY_H
#define GUI_ENTRYENTRY_H

#include <QFrame>

#include "Data/entry.h"

class GUI_EntryEntry : public QFrame
{
    Q_OBJECT
public:
    GUI_EntryEntry(QWidget *parent = 0);
    virtual ~GUI_EntryEntry(){}

    virtual  void setContent(Entry* md, int idx)=0;
    void setWidth(int w)
    {
        this->resize(w, this->height());
    }

signals:

public slots:

};

#endif // GUI_ENTRYENTRY_H
