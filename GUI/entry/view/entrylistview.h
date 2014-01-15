#ifndef ENTRYLISTVIEW_H
#define ENTRYLISTVIEW_H

#include <QListView>

#include "Data/entry.h"
#include "GUI/entry/model/entrylistmodel.h"
#include "GUI/entry/delegate/entryitemdelegate.h"

class EntryListView : public QListView
{
    Q_OBJECT

signals:
    void context_menu_emitted(const QPoint&);
    void sig_rows_removed(const QList<int> &, bool);
    void sig_rows_moved(const QList<int>&, int);
    void sig_info_clicked();
    void sig_remove_clicked();
    void sig_edit_clicked();
    void sig_sel_changed(const QModelIndex&/*const EntryList&, const QList<int>&*/);
    void sig_double_clicked(int);
    void sig_no_focus();


private slots:
    void forbid_mimedata_destroyable();
    void edit_clicked();
    void info_clicked();
    void remove_clicked();

    void row_pressed(const QModelIndex&);
    void row_double_clicked(const QModelIndex&);
    void row_released(const QModelIndex&);

public:
    EntryListView(QWidget* parent=0);
    virtual ~EntryListView();



    void set_drag_enabled(bool b);
    void clear();
    void fill(const EntryList& v_metadata, int cur_play_idx);
    void scrollUp();
    void scrollDown();
    void set_current_track(int row);
    int get_num_rows();
    void show_big_items(bool);
    void select_row(int i);


    QList<int> get_selections();
    Entry* get_selection();
    EntryListModel* get_model();

    void UpdateAndSave();





protected:
    // overloaded stuff
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *e);
    void selectionChanged ( const QItemSelection & selected, const QItemSelection & deselected );


private:

    void clear_selection();

    void select_all();
    int calc_dd_line(QPoint pos);
    void set_delegate_max_width(int n_items);

    void clear_drag_lines(int row);

    void remove_cur_selected_rows(bool select_next_row=true);
    void select_rows(QList<int> lst);
    void goto_row(int row);
    int get_min_selected();


private:
    QWidget*        _parent;

    bool            _drag;
    bool            _drag_allowed;
    bool            _inner_drag_drop;

    QPoint          _drag_pos;
    QDrag*          _qDrag;
    int             _last_known_drag_row;
    bool            _ignore_selection_changes;

    QList<int>      _cur_selected_rows;

//    ContextMenu* 	_rc_menu;

    EntryListModel*              _model;
    EntryItemDelegate* 	        _delegate;
    bool            _sel_changed;

};

#endif // ENTRYLISTVIEW_H
