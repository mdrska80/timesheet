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

    int rowCount(const QModelIndex &parent) const;

    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Entry* GetEntryAtIndex(const QModelIndex &index);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    
signals:
    
public slots:

private:
    QList<Entry*> entries;
    
};

#endif // ENTRYLISTMODEL_H
