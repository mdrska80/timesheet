#ifndef ENTRYLISTMODEL_H
#define ENTRYLISTMODEL_H

#include <QAbstractListModel>
#include "../../../Data/entry.h"
#include "../../../Storage/persistentstorage_xml.h"

#include "../../../Filters/filterbase.h"

class EntryListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    EntryListModel(QObject *parent = 0);
    ~EntryListModel();

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent) const;

    void insertEntry(Entry* e);

    bool insertRows(int row, int count, const QModelIndex &parent=QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent=QModelIndex());
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Entry* GetEntryAtIndex(const QModelIndex &index);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    //QList<Entry*> entries;

    void set_selected(QList<int>& rows);
    bool is_selected(int row) const ;
    QList<int>          _selected_rows;
    PersistentStorage_XML*  _storage;

    void ApplyFilter();
    void ApplyFilter(FilterBase* filter);
    void ApplySearch(QString filter);

    FilterBase* fActive;


signals:
    
public slots:

private:
    
};

#endif // ENTRYLISTMODEL_H
