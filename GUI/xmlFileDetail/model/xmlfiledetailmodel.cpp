#include "xmlfiledetailmodel.h"

XmlFileDetailModel::XmlFileDetailModel(QObject *parent) :
    QAbstractListModel(parent)
{
    _storage = new FileInfoStorage();
}

XmlFileDetailModel::~XmlFileDetailModel()
{
    delete _storage;
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

        QString qs = e->filename.replace("\n", "<br/>");
        return QString("<b>Title:</b> %1<br/><b>Description:</b> %2")
                .arg(e->company);
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

