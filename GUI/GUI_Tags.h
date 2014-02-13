#ifndef GUI_TAGS_H
#define GUI_TAGS_H

#include <QWidget>
#include <QList>
#include "GUI_Tag.h"
#include "../Common/tscore.h"


namespace Ui {
class GUI_Tags;
}

class GUI_Tags : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_Tags(QWidget *parent = 0);
    ~GUI_Tags();

    QStringList tags;
    QList<GUI_Tag*> tagControls;

    void set_tags(QStringList lst);
    void clear_removed(QStringList lst);
    bool find_tag(QString tag);

    bool checkNew(QStringList newLst);


    QString textualTags;

private:
    Ui::GUI_Tags *ui;
};

#endif // GUI_TAGS_H
