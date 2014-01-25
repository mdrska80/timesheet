#ifndef GUI_LEVELPAINTER_H
#define GUI_LEVELPAINTER_H

#include "GUI/EngineColorStyleChooser.h"
#include <QCloseEvent>
#include <QShowEvent>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QAction>
#include <QColor>
#include <QTimer>

namespace Ui {
class GUI_LevelPainter;
}

class GUI_LevelPainter : public QWidget
{
    Q_OBJECT
public:
    explicit GUI_LevelPainter(QWidget *parent=0);
    ~GUI_LevelPainter();

    static QString getVisName(){ return tr("Le&vel"); }

signals:
    void sig_show(bool);
    void sig_right_clicked(int);

protected:

    void showEvent(QShowEvent *);
    //void closeEvent(QCloseEvent *);
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent *e);
    void resizeEvent(QResizeEvent *e);

public slots:
    void set_level(float, float);
    void psl_stop();
    void psl_style_update(bool inner=false);


private slots:
    void timed_out();

private:
    Ui::GUI_LevelPainter* ui;

    float _level[2];

    EngineColorStyleChooser* _ecsc;
    ColorStyle _cur_style;
    int _cur_style_idx;

    int** _steps;
    QTimer* _timer;
    bool    _timer_stopped;

    void resize_steps(int n_rects);
    void reload();


    
};

#endif // GUI_LEVELPAINTER_H
