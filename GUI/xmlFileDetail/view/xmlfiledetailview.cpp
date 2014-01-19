#include "xmlfiledetailview.h"

XmlFileDetailView::XmlFileDetailView(QWidget *parent) :
    QListView(parent)
{
    _parent = parent;
    _model = new XmlFileDetailModel(this);
    _delegate = new XmlFileDetailDelegate(this, true);
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

XmlFileDetailView::~XmlFileDetailView()
{
    delete _model;
}

void XmlFileDetailView::mousePressEvent(QMouseEvent* event) {

    QPoint pos_org = event->pos();
    QPoint pos = QWidget::mapToGlobal(pos_org);
    QItemSelection sel, desel;
    switch (event->button()) {

    case Qt::LeftButton:

        _sel_changed = false;
        QListView::mousePressEvent(event);
        if(!_sel_changed)
        {
            selectionChanged(sel, desel);
        }
        break;

    case Qt::RightButton:
        _sel_changed = false;
        QListView::mousePressEvent(event);
        if(!_sel_changed){
            selectionChanged(sel, desel);
        }
        break;

    default:
        break;
    }
}


// get the min index of selected rows
int XmlFileDetailView::get_min_selected(){

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
void XmlFileDetailView::goto_row(int row){

    if( (row >= _model->rowCount()) || (row < 0) ) return;

    QModelIndex idx = _model->index(row, 0);

    this->scrollTo(idx);
}


void XmlFileDetailView::keyPressEvent(QKeyEvent* event){

    int key = event->key();

    Qt::KeyboardModifiers  modifiers = event->modifiers();
    QModelIndexList lst = this->selectedIndexes();

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

    default: break;
    }

    if(new_row != -1) goto_row(new_row);
}

void XmlFileDetailView::resizeEvent(QResizeEvent *e){

    this->set_delegate_max_width(_model->rowCount());
    e->accept();
}

int XmlFileDetailView::get_num_rows(){
    return _model->rowCount();
}

void XmlFileDetailView::clear_selection(){

    this->selectionModel()->clearSelection();
    this->clearSelection();
}

void XmlFileDetailView::select_row(int i){

    if(_model->rowCount() == 0) return;
    if(i > _model->rowCount() - 1) i = _model->rowCount() - 1;
    if(i < 0) i = 0;
    QList<int> lst;
    lst << i;
    select_rows(lst);

    this->selectionModel()->setCurrentIndex(_model->index(i), QItemSelectionModel::Select);
}

void XmlFileDetailView::select_rows(QList<int> lst){

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

void XmlFileDetailView::select_all(){
    selectAll();
}

void XmlFileDetailView::selectionChanged ( const QItemSelection & selected, const QItemSelection & deselected ){

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

    if (selected.indexes().size() > 0)
    {
        QModelIndex idx = selected.indexes()[0];
    }

    _cur_selected_rows = idx_list_int;
    _sel_changed = true;
}


QList<int> XmlFileDetailView::get_selections(){

    QList<int> idx_list_int;
    QModelIndexList idx_list = this->selectionModel()->selectedRows();

    foreach(QModelIndex model_idx, idx_list){
        idx_list_int.push_back(model_idx.row());
    }

    return idx_list_int;
}

EntryFileInfo* XmlFileDetailView::get_selection()
{
    QList<int> sels = get_selections();
    if (sels.size() > 0)
    {
        QModelIndex idx = _model->index(sels[0], 0);
        EntryFileInfo *e = _model->GetEntryAtIndex(idx);
        return e;
    }

    return NULL;
}

void XmlFileDetailView::scrollUp(){
    QPoint p(5, 5);
    int cur_row = this->indexAt(p).row();
    if(cur_row <= 0) return;

    this->scrollTo(_model->index(cur_row - 1));
}

void XmlFileDetailView::scrollDown(){
    QPoint p(5, this->y() + this->height() - 5);
    int cur_row = this->indexAt(p).row();
    if(cur_row <= 0) return;

    this->scrollTo(_model->index(cur_row - 1));
}

void XmlFileDetailView::remove_cur_selected_rows(bool select_next_row)
{
    foreach (int i, _cur_selected_rows) {
        _model->removeRow(i);
        select_row(i);
        this->update();
    }
}


void XmlFileDetailView::show_big_items(bool big){

    if(_delegate) delete _delegate;
    _delegate = new XmlFileDetailDelegate(this, !big);

    this->set_delegate_max_width(_model->rowCount());
    this->setItemDelegate(_delegate);

    this->reset();
}

void XmlFileDetailView::set_delegate_max_width(int n_items){

    bool scrollbar_visible = (( n_items * _delegate->rowHeight() ) >= this->height());

    int max_width = this->width();
    if(scrollbar_visible)
        max_width -= verticalScrollBar()->width();

    _delegate->setMaxWidth(max_width);
}

XmlFileDetailModel* XmlFileDetailView::get_model()
{
    return _model;
}



