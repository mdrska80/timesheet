#ifndef GUI_ENTRYENTRYBIG_H
#define GUI_ENTRYENTRYBIG_H

#include <QFrame>
#include "gui_entryentry.h"

namespace Ui {
class GUI_EntryEntryBig;
}

class GUI_EntryEntryBig : public GUI_EntryEntry
{
    Q_OBJECT

public:
    explicit GUI_EntryEntryBig(QWidget *parent = 0);
    ~GUI_EntryEntryBig();

    virtual void setContent(Entry* e);


private:
    Ui::GUI_EntryEntryBig *ui;
};

#endif // GUI_ENTRYENTRYBIG_H
