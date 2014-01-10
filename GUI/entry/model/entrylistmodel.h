#ifndef ENTRYLISTMODEL_H
#define ENTRYLISTMODEL_H

#include <QAbstractListModel>
#include "Data/entry.h"

class EntryListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit EntryListModel(QObject *parent = 0);
    EntryListModel(QList<Entry*> items, QObject* parent);

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent) const;

    bool insertRows(int row, int count, const QModelIndex &parent=QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent=QModelIndex());
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Entry* GetEntryAtIndex(const QModelIndex &index);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    QList<Entry*> entries;

    void set_selected(QList<int>& rows);
    bool is_selected(int row) const ;
    QList<int>          _selected_rows;

signals:
    
public slots:

private:
    
};

#endif // ENTRYLISTMODEL_H
