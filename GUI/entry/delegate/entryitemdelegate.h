#ifndef ENTRYITEMDELEGATE_H
#define ENTRYITEMDELEGATE_H

#include <QItemDelegate>
#include <QListView>

#include "Data/entry.h"
#include "GUI/entry/entry/gui_entryentry.h"
#include "GUI/entry/entry/gui_entryentrysmall.h"
#include "GUI/entry/entry/gui_entryentrybig.h"

class EntryItemDelegate : public QItemDelegate
{
public:
    EntryItemDelegate(QListView *parent, bool small);
    virtual ~EntryItemDelegate();

    virtual void paint( QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const;


    QSize sizeHint(const QStyleOptionViewItem &option,
                         const QModelIndex &index) const;

    void setMaxWidth(int w);
    int rowHeight();

    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    int		_rendered_items;
    int		_row_height;
    int		_max_width;
    QListView*	_parent;
    GUI_EntryEntry *_pl_entry;

signals:

public slots:

};

#endif // ENTRYITEMDELEGATE_H
