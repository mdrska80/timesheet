#include "xmlfiledetailmodel.h"
#include "Common/tscore.h"

XmlFileDetailModel::XmlFileDetailModel(QObject *parent) :
    QAbstractListModel(parent)
{
    _storage = &TSCore::I().fiStorage;
}

int XmlFileDetailModel::rowCount(const QModelIndex& ) const
{
    return _storage->infos.size();
}

QVariant XmlFileDetailModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(role == Qt::ToolTipRole)
    {
        EntryFileInfo* e = _storage->infos.at(index.row());

        QString titles;
        int cnt = e->titles.size();
        for(int i=0;i<cnt;i++)
        {
            titles += e->titles[i]+"<br/>";
        }

        return QString("<b>Titles:</b> %1")
                .arg(titles);
    }


    if (role == Qt::DisplayRole){
       return QVariant();
    }

    if (role == Qt::WhatsThisRole){
        return _storage->infos.at(index.row())->toVariant();
    }

    else
        return QVariant();
}

EntryFileInfo* XmlFileDetailModel::GetEntryAtIndex(const QModelIndex &index)
{
    if (index.isValid())
    {
        int row = index.row();
        if (row < _storage->infos.size())
        {
            EntryFileInfo* eToReturn = _storage->infos.at(row);
            return eToReturn;
        }
    }

    return NULL;
}


void XmlFileDetailModel::set_selected(QList<int>& rows){
    _selected_rows = rows;
    for(int i=0; i< _storage->infos.size(); i++){
        _storage->infos.at(i)->pl_selected = rows.contains(i);
    }
}

bool XmlFileDetailModel::is_selected(int row) const {
    return _selected_rows.contains(row);
}

