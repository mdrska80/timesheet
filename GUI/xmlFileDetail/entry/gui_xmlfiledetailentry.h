#ifndef GUI_XMLFILEDETAILENTRY_H
#define GUI_XMLFILEDETAILENTRY_H

#include <QFrame>

#include "Data/entryfileinfo.h"

class GUI_XmlFileDetailEntry : public QFrame
{
    Q_OBJECT
public:
    explicit GUI_XmlFileDetailEntry(QWidget *parent = 0);
    virtual ~GUI_XmlFileDetailEntry(){}

    virtual void setContent(EntryFileInfo* md)=0;
    void setWidth(int w)
    {
        this->resize(w, this->height());
    }

signals:

public slots:

};

#endif // GUI_XMLFILEDETAILENTRY_H
