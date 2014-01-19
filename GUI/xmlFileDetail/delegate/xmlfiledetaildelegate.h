#ifndef XMLFILEDETAILDELEGATE_H
#define XMLFILEDETAILDELEGATE_H

#include <QItemDelegate>
#include <QListView>
#include <QPainter>
#include "GUI/xmlFileDetail/entry/gui_xmlfiledetailentry.h"
#include "GUI/xmlFileDetail/entry/gui_xmlfiledetailentrybig.h"
#include "GUI/xmlFileDetail/model/xmlfiledetailmodel.h"
#include "Common/helper.h"

class XmlFileDetailDelegate : public QItemDelegate
{
public:
    XmlFileDetailDelegate(QListView* parent, bool small);

    virtual ~XmlFileDetailDelegate();

    virtual void paint( QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const;


    QSize sizeHint(const QStyleOptionViewItem &option,
                         const QModelIndex &index) const;

    QString get_fg_color(int val_bg);

private:
    int		_rendered_items;
    int		_row_height;
    int		_max_width;
    QListView*	_parent;
    GUI_XmlFileDetailEntry *_pl_entry;

};

#endif // XMLFILEDETAILDELEGATE_H
