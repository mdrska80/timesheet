#ifndef GUI_XMLFILEDETAILENTRYBIG_H
#define GUI_XMLFILEDETAILENTRYBIG_H

#include <QFrame>
#include "gui_xmlfiledetailentry.h"
#include "Common/tscore.h"

namespace Ui {
class GUI_XmlFileDetailEntryBig;
}

class GUI_XmlFileDetailEntryBig : public GUI_XmlFileDetailEntry
{
    Q_OBJECT

public:
    explicit GUI_XmlFileDetailEntryBig(QWidget *parent = 0);
    ~GUI_XmlFileDetailEntryBig();

    virtual void setContent(EntryFileInfo* md);
    void SetImage(EntryFileInfo* md);


private:
    Ui::GUI_XmlFileDetailEntryBig *ui;
};

#endif // GUI_XMLFILEDETAILENTRYBIG_H
