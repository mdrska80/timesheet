#include "entrylistview.h"

#include <QEvent>
#include <QPoint>
#include <QDrag>
#include <QList>
#include <QMenu>
#include <QModelIndex>
#include <QMouseEvent>
#include <QListView>
#include <QScrollBar>

EntryListView::EntryListView(QWidget* parent) : QListView(parent) {

    _drag_allowed = true;
    _inner_drag_drop = false;
    _parent = parent;
    _qDrag = 0;
    _last_known_drag_row = -1;
    _model = new EntryListModel(this);
    _delegate = new EntryItemDelegate(this, true);
    //_rc_menu = 0;

    this->setModel(_model);
    this->setDragEnabled(true);
    this->setAcceptDrops(true);
    this->setSelectionRectVisible(true);
    this->setAlternatingRowColors(true);
    this->setMovement(QListView::Free);

    connect(this, SIGNAL(pressed(const QModelIndex&)), this, SLOT(row_pressed(const QModelIndex&)));
    connect(this, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(row_double_clicked(const QModelIndex&)));
    connect(this, SIGNAL(clicked(const QModelIndex&)), this, SLOT(row_released(const QModelIndex&)));
}

EntryListView::~EntryListView() {

    //delete _rc_menu;
    delete _model;
}


void EntryListView::mousePressEvent(QMouseEvent* event) {

    QPoint pos_org = event->pos();
    QPoint pos = QWidget::mapToGlobal(pos_org);
    QItemSelection sel, desel;
    switch (event->button()) {

    case Qt::LeftButton:
        if(!_drag_allowed) break;

        _sel_changed = false;
        QListView::mousePressEvent(event);
        if(!_sel_changed){
            selectionChanged(sel, desel);
        }

        if ((this->model()->rowCount()) * 33 > event->pos().y())
            _drag_pos = event->pos();

        else {
            _drag_pos.setY(-10);
            _drag = false;
        }

        break;

    case Qt::RightButton:
        _drag = false;
        _sel_changed = false;
        QListView::mousePressEvent(event);
        if(!_sel_changed){
            selectionChanged(sel, desel);
        }

        pos.setY(pos.y());
        pos.setX(pos.x() + 10);

        //_rc_menu->exec(pos);

        break;

    default:
        _drag = false;
        break;
    }
}


void EntryListView::mouseMoveEvent(QMouseEvent* event) {

    QPoint pos = event->pos();
    int distance =  abs(pos.x() - _drag_pos.x()) +	abs(pos.y() - _drag_pos.y());

    if (_drag && _qDrag && (distance > 10) && _drag_allowed) {
        _qDrag->exec(Qt::CopyAction);
    }
}


void EntryListView::mouseReleaseEvent(QMouseEvent* event) {

    switch (event->button()) {

    case Qt::LeftButton:

        if(_qDrag) {
            delete _qDrag;
            _qDrag = NULL;
        }

        QListView::mouseReleaseEvent(event);
        event->accept();

        _drag = false;
        break;

    default: break;
    }
}


// get the min index of selected rows
int EntryListView::get_min_selected(){

    QModelIndexList lst = this->selectedIndexes();
    int min_row = 5000000;

    if(lst.size() == 0) {
        return 0;
    }

    foreach(QModelIndex i, lst){

        if(i.row() < min_row){
            min_row = i.row();
        }
    }

    return min_row;
}

// mark row as currently pressed
void EntryListView::goto_row(int row){

    if( (row >= _model->rowCount()) || (row < 0) ) return;

    QModelIndex idx = _model->index(row, 0);
    row_released(idx);

    this->scrollTo(idx);
}


void EntryListView::keyPressEvent(QKeyEvent* event){

    int key = event->key();

    Qt::KeyboardModifiers  modifiers = event->modifiers();
    QModelIndexList lst = this->selectedIndexes();
//    foreach(QModelIndex idx, lst){
//
//    }

    QListView::keyPressEvent(event);


    int new_row = -1;
    int min_row = get_min_selected();

    switch(key){
    case Qt::Key_A:
        if( modifiers & Qt::ControlModifier ) select_all();
        break;

    case Qt::Key_Delete:
        remove_cur_selected_rows();
        //select_row(_model->rowCount());
        break;

    case Qt::Key_End:
        new_row = _model->rowCount() - 1;
        break;

    case Qt::Key_Home:
        new_row = 0;
        break;
    case Qt::Key_Insert:
        _model->insertRow(_model->rowCount());
        select_row(_model->rowCount());
        break;

    case Qt::Key_Return:
    case Qt::Key_Enter:
        this->sig_double_clicked(min_row);
        break;

    case Qt::Key_Tab:
        emit sig_no_focus();
        break;

    default: break;
    }

    if(new_row != -1) goto_row(new_row);
}

void EntryListView::resizeEvent(QResizeEvent *e){

    this->set_delegate_max_width(_model->rowCount());
    e->accept();

}

void EntryListView::forbid_mimedata_destroyable(){
    _qDrag = NULL;
}

void EntryListView::set_drag_enabled(bool b){
    _drag_allowed = b;
}


int EntryListView::get_num_rows(){
    return _model->rowCount();
}

void EntryListView::set_current_track(int row){

    for(int i=0; i<_model->rowCount(); i++){
        QModelIndex idx = _model->index(i);
        Entry* md = _model->GetEntryAtIndex(idx);
        //Entry* md = new Entry();
        QVariant v = _model->data(idx, Qt::WhatsThisRole);
        //if(!Entry::fromVariant(v, md)) continue;
        md->pl_playing = (row == i);

        _model->setData(idx, md->toVariant(), Qt::EditRole);
    }

    QModelIndex new_idx = _model->index(row);
    scrollTo(new_idx);
}


void EntryListView::edit_clicked(){
    emit sig_edit_clicked();
}


void EntryListView::info_clicked(){
    emit sig_info_clicked();
}

void EntryListView::remove_clicked(){
    remove_cur_selected_rows();
}

void EntryListView::clear(){
    clear_selection();
    _model->removeRows(0, _model->rowCount());
}

#define IGNORE_SELECTION_CHANGES(b) _ignore_selection_changes = b

void EntryListView::fill(const EntryList &v_md, int cur_play_idx){


    this->set_delegate_max_width((int) v_md.size());
    _cur_selected_rows.clear();

    IGNORE_SELECTION_CHANGES(true);
        _model->removeRows(0, _model->rowCount());
    IGNORE_SELECTION_CHANGES(false);

    if(v_md.size() == 0) return;

    IGNORE_SELECTION_CHANGES(true);
        _model->insertRows(0, v_md.size());
    IGNORE_SELECTION_CHANGES(false);

    QList<int> selected_rows;

    QModelIndex idx_cur_playing = _model->index(0);
    for(uint i=0; i<v_md.size(); i++){
        Entry* md = v_md[i];

        QModelIndex model_idx = _model->index(i, 0);

        md->pl_playing = (cur_play_idx == (int) i);
        if(md->pl_playing) idx_cur_playing = model_idx;

        if(md->pl_selected)
            selected_rows << i;

        _model->setData(model_idx, md->toVariant(), Qt::EditRole);
    }

    this->select_rows(selected_rows);
    this->scrollTo(idx_cur_playing, QListView::EnsureVisible);
}

void EntryListView::row_pressed(const QModelIndex& idx){

    QList<int> selected_rows = get_selections();
    _inner_drag_drop = true;
}

void EntryListView::row_released(const QModelIndex& idx){
    _inner_drag_drop = false;
}

void EntryListView::row_double_clicked(const QModelIndex& idx){
    _inner_drag_drop = false;

    if(idx.isValid()) emit sig_double_clicked(idx.row());
}

void EntryListView::clear_selection(){

    this->selectionModel()->clearSelection();
    this->clearSelection();
}

void EntryListView::select_row(int i){

    if(_model->rowCount() == 0) return;
    if(i > _model->rowCount() - 1) i = _model->rowCount() - 1;
    if(i < 0) i = 0;
    QList<int> lst;
    lst << i;
    select_rows(lst);

    this->selectionModel()->setCurrentIndex(_model->index(i), QItemSelectionModel::Select);
}

void EntryListView::select_rows(QList<int> lst){

    QItemSelectionModel* sm = this->selectionModel();
    QItemSelection sel;
    if(lst.size() > 0)
        this->setCurrentIndex(_model->index(lst[0]));

    foreach(int row, lst){
        QModelIndex idx = _model->index(row);

        sm->select(idx, QItemSelectionModel::Select);
        sel.merge(sm->selection(), QItemSelectionModel::Select);
    }

    sm->select(sel,QItemSelectionModel::Select);

    _cur_selected_rows = lst;

}

void EntryListView::select_all(){
    selectAll();
}

void EntryListView::selectionChanged ( const QItemSelection & selected, const QItemSelection & deselected ){

    if(_ignore_selection_changes) return;
    QModelIndexList idx_list = this->selectionModel()->selectedRows();

    QListView::selectionChanged(selected, deselected);

    QList<int> idx_list_int;

    foreach(QModelIndex model_idx, idx_list){
        if(idx_list_int.contains(model_idx.row())) continue;

        idx_list_int << model_idx.row();
    }

   _model->set_selected(idx_list_int);

    if(selected.indexes().size() > 0)
        this->scrollTo(selected.indexes()[0]);

    //EntryList v_md;
//    _model->get_metadata(idx_list_int, v_md);
    if (selected.indexes().size() > 0)
    {
        QModelIndex idx = selected.indexes()[0];
        emit sig_sel_changed(idx);
    }

    _cur_selected_rows = idx_list_int;
    _sel_changed = true;
}


QList<int> EntryListView::get_selections(){

    QList<int> idx_list_int;
    QModelIndexList idx_list = this->selectionModel()->selectedRows();

    foreach(QModelIndex model_idx, idx_list){
        idx_list_int.push_back(model_idx.row());
    }

    return idx_list_int;
}

Entry* EntryListView::get_selection()
{
    QList<int> sels = get_selections();
    if (sels.size() > 0)
    {
        QModelIndex idx = _model->index(sels[0], 0);
        Entry *e = _model->GetEntryAtIndex(idx);
        return e;
    }

    return NULL;
}


// remove the black line under the titles
void  EntryListView::clear_drag_lines(int row){

    for(int i=row-3; i<=row+3; i++){

        QModelIndex idx = _model->index(i, 0);
        if(!idx.isValid() || idx.row() < 0 || idx.row() >= _model->rowCount())
            continue;

        Entry* md = _model->GetEntryAtIndex(idx);

//        QVariant mdVariant =_model->data(idx, Qt::WhatsThisRole);
//        if(Entry::fromVariant(mdVariant, md)){

            md->pl_dragged = false;
            _model->setData(idx, md->toVariant(), Qt::EditRole);
//        }
    }
}


int EntryListView::calc_dd_line(QPoint pos){

    if(pos.y() < 0) {
        return -1;
    }
    int row = this->indexAt(pos).row();

    if(row <= -1) row = _model->rowCount()-1;
    return row;
}

void EntryListView::scrollUp(){
    QPoint p(5, 5);
    int cur_row = this->indexAt(p).row();
    if(cur_row <= 0) return;

    this->scrollTo(_model->index(cur_row - 1));
}

void EntryListView::scrollDown(){
    QPoint p(5, this->y() + this->height() - 5);
    int cur_row = this->indexAt(p).row();
    if(cur_row <= 0) return;

    this->scrollTo(_model->index(cur_row - 1));
}

void EntryListView::remove_cur_selected_rows(bool select_next_row)
{
    foreach (int i, _cur_selected_rows) {
        _model->removeRow(i);
        select_row(i);
        this->update();
    }

    emit sig_rows_removed(_cur_selected_rows, select_next_row);
}


void EntryListView::show_big_items(bool big){

    if(_delegate) delete _delegate;
    _delegate = new EntryItemDelegate(this, !big);

    this->set_delegate_max_width(_model->rowCount());
    this->setItemDelegate(_delegate);

    this->reset();
}


void EntryListView::set_delegate_max_width(int n_items){

    bool scrollbar_visible = (( n_items * _delegate->rowHeight() ) >= this->height());

    int max_width = this->width();
    if(scrollbar_visible)
        max_width -= verticalScrollBar()->width();

    _delegate->setMaxWidth(max_width);
}

EntryListModel* EntryListView::get_model()
{
    return _model;
}

void EntryListView::UpdateAndSave()
{
    this->update();
    _model->_storage->Save();
    //_model->ApplyFilter();
}
