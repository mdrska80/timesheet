#ifndef XMLFILEDETAILVIEW_H
#define XMLFILEDETAILVIEW_H

#include <QListView>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QScrollBar>

#include "GUI/xmlFileDetail/delegate/xmlfiledetaildelegate.h"
#include "GUI/xmlFileDetail/model/xmlfiledetailmodel.h"

class XmlFileDetailView : public QListView
{
    Q_OBJECT
public:
    explicit XmlFileDetailView(QWidget *parent = 0);
    virtual ~XmlFileDetailView();

    int get_num_rows();
    void select_last_row();
    void select_row(int i);
    QList<int> get_selections();
    EntryFileInfo* get_selection();
    XmlFileDetailModel* get_model();

    void scrollUp();
    void scrollDown();
    void show_big_items(bool);
    void ApplyFilter(QString filter);


signals:

public slots:

protected:
    // overloaded stuff
    void mousePressEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *e);
    void selectionChanged ( const QItemSelection & selected, const QItemSelection & deselected );


private:
    QWidget*                _parent;

    QList<int>              _cur_selected_rows;
    bool                    _sel_changed;

    XmlFileDetailModel*     _model;
    XmlFileDetailDelegate* 	_delegate;

    bool                    _ignore_selection_changes;

    void remove_cur_selected_rows(bool select_next_row=true);
    void select_rows(QList<int> lst);
    void goto_row(int row);
    int get_min_selected();
    void clear_selection();
    void select_all();
    void set_delegate_max_width(int n_items);


};

#endif // XMLFILEDETAILVIEW_H
