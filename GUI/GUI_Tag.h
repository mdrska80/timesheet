#ifndef GUI_TAG_H
#define GUI_TAG_H

#include <QWidget>
#include <QString>
#include <QColor>
#include <QPaintEvent>

namespace Ui {
class GUI_Tag;
}

class GUI_Tag : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_Tag(QWidget *parent = 0);
    ~GUI_Tag();

    void set_tag(QString text, QColor color);
    int determineWidth();

    // overrides
//    void paintEvent(QPaintEvent *e);


private:
    Ui::GUI_Tag *ui;

    QColor color;
};

#endif // GUI_TAG_H
