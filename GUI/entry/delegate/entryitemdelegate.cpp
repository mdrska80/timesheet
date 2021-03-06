#include <QPainter>

#include "entryitemdelegate.h"
#include "../../../GUI/entry/model/entrylistmodel.h"

EntryItemDelegate::EntryItemDelegate(QListView* parent, bool small){

    if(small){
        _row_height = 22;
        _pl_entry = new GUI_EntryEntrySmall();
    }
    else{
        _row_height = 38;
        _pl_entry = new GUI_EntryEntryBig();
    }

    _parent = parent;
    _rendered_items = 0;
}

EntryItemDelegate::~EntryItemDelegate(){
    delete _pl_entry;
    _row_height = 0;
}


void EntryItemDelegate::paint( QPainter *painter, const QStyleOptionViewItem &option,
                     const QModelIndex &index) const
{

    if(!index.isValid()) return;

    QRect rect(option.rect);
    _pl_entry->setMaximumSize(_max_width, _row_height);
    _pl_entry->setMinimumSize(_max_width, _row_height);
    _pl_entry->resize(_max_width, _row_height);

    EntryListModel* elm = (EntryListModel*)index.model();
    Entry* md = elm->GetEntryAtIndex(index);

    // set data to delegate
    _pl_entry->setContent(md);

    QString style;
    QPalette palette = _parent->palette();

    QColor col_background = palette.color(QPalette::Active, QPalette::Background);
    QColor col_highlight = palette.color(QPalette::Active, QPalette::Highlight);
    QColor col_highlight_lighter = col_highlight.darker(140);

    int highlight_val = col_highlight.lightness();
    int playing_val = col_highlight_lighter.lightness();
    int background_val = col_background.lightness();

    if(md->pl_playing){
        style = QString("border: none; background-color: ") +
            col_highlight_lighter.name() + "; " +
            Helper::get_fg_color(playing_val);

        if (md->pl_selected)
        {
            style = QString("border: none; background-color: ") +
                col_highlight.name() + ";" +
                Helper::get_fg_color(highlight_val);
        }
    }

    else if(md->is_disabled){
        style = QString("border: none; color: #A0A0A0; background-color: transparent;");
    }

    else if(!md->pl_selected){
        style = QString("border: none; background-color: transparent; ") +
            Helper::get_fg_color(background_val);
    }
    else
    {
        style = QString("border: none; background-color: ") +
            col_highlight.name() + ";" +
            Helper::get_fg_color(highlight_val);
    }

    if(md->title.toLower().contains("svátek"))
    {
        style = QString("border: none; background-color: ") +
            colorGreen + ";" +
            Helper::get_fg_color(highlight_val);
    }
    if(md->title.toLower().contains("dovolená"))
    {
        style = QString("border: none; background-color: ") +
            colorYellow + "; color:" +colorBlack;
            //Helper::get_fg_color(highlight_val);
    }

    //int y = rect.topLeft().y() +  _pl_entry->height() -1;
    _pl_entry->setStyleSheet(style);
    if(md->is_disabled) _pl_entry->setDisabled(true);

    painter->save();
    painter->translate(0, 0);

    _pl_entry->render(painter, rect.topLeft() );

    painter->restore();
}


QSize EntryItemDelegate::sizeHint(const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    return QSize(_max_width, _row_height);
}



void EntryItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    Q_UNUSED(editor);
    Q_UNUSED(index);
}

void EntryItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    Q_UNUSED(editor);
    Q_UNUSED(index);
    Q_UNUSED(model);
}

QWidget* EntryItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(parent);
    Q_UNUSED(option);
    Q_UNUSED(index);

    return 0;
}

void EntryItemDelegate::setMaxWidth(int w){
    _max_width = w;
}

int EntryItemDelegate::rowHeight(){
    return _row_height;
}

