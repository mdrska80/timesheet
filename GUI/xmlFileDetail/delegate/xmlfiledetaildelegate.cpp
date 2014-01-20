#include "xmlfiledetaildelegate.h"

XmlFileDetailDelegate::XmlFileDetailDelegate(QListView* parent, bool small)
{
    if(small){
        _row_height = 22;
        _pl_entry = new GUI_XmlFileDetailEntryBig();
    }
    else{
        _row_height = 28;
        _pl_entry = new GUI_XmlFileDetailEntryBig();
    }

    _parent = parent;
    _rendered_items = 0;
}

XmlFileDetailDelegate::~XmlFileDetailDelegate(){
    delete _pl_entry;
    _row_height = 0;
}

void XmlFileDetailDelegate::paint( QPainter *painter, const QStyleOptionViewItem &option,
                     const QModelIndex &index) const
{

    if(!index.isValid()) return;


    QRect rect(option.rect);
    _pl_entry->setMaximumSize(_max_width, _row_height);
    _pl_entry->setMinimumSize(_max_width, _row_height);
    _pl_entry->resize(_max_width, _row_height);

    XmlFileDetailModel* elm = (XmlFileDetailModel*)index.model();
    EntryFileInfo* md = elm->GetEntryAtIndex(index);

    // set data to delegate
    _pl_entry->setContent(md);

    QString style;
    QPalette palette = _parent->palette();

    QColor col_background = palette.color(QPalette::Active, QPalette::Background);
    QColor col_highlight = palette.color(QPalette::Active, QPalette::Highlight);
    QColor col_highlight_lighter = col_highlight.darker(140);

    int highlight_val = col_highlight.lightness();
    int background_val = col_background.lightness();

    if(md->pl_selected){
        style = QString("border: none; background-color: ") +
            col_highlight.name() + ";" +
            Helper::get_fg_color(highlight_val);
    }
    else if(!md->isValid)
    {
        // if it is not valid...
        style = QString("border: none; background-color: ") +
            col_highlight_lighter.name() + ";" +
            Helper::get_fg_color(highlight_val);
    }

    else
    {
        style = QString("border: none; background-color: transparent; ") +
            Helper::get_fg_color(background_val);
    }

    _pl_entry->setStyleSheet(style);

    painter->save();
    painter->translate(0, 0);

    _pl_entry->render(painter, rect.topLeft() );

    painter->restore();
}

QSize XmlFileDetailDelegate::sizeHint(const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    return QSize(_max_width, _row_height);
}

void XmlFileDetailDelegate::setMaxWidth(int w){
    _max_width = w;
}

int XmlFileDetailDelegate::rowHeight(){
    return _row_height;
}



