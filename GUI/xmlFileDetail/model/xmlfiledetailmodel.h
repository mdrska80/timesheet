#ifndef XMLFILEDETAILMODEL_H
#define XMLFILEDETAILMODEL_H

#include <QAbstractListModel>
#include "Data/entryfileinfo.h"
#include "Storage/fileinfostorage.h"


class XmlFileDetailModel : public QAbstractListModel
{
    Q_OBJECT
public:
    XmlFileDetailModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

    EntryFileInfo* GetEntryAtIndex(const QModelIndex &index);
    void ApplyFilter(QString filter);


    void set_selected(QList<int>& rows);
    bool is_selected(int row) const ;
    QList<int>          _selected_rows;
    FileInfoStorage*  _storage;


};

#endif // XMLFILEDETAILMODEL_H
