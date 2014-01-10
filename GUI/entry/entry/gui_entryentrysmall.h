#ifndef GUI_ENTRYENTRYSMALL_H
#define GUI_ENTRYENTRYSMALL_H

#include <QFrame>

#include "gui_entryentry.h"

namespace Ui {
class GUI_EntryEntrySmall;
}

class GUI_EntryEntrySmall : public GUI_EntryEntry
{
    Q_OBJECT

public:
    explicit GUI_EntryEntrySmall(QWidget *parent = 0);
    ~GUI_EntryEntrySmall();

    virtual void setContent(Entry* e, int idx);


private:
    Ui::GUI_EntryEntrySmall *ui;
};

#endif // GUI_ENTRYENTRYSMALL_H
