#include "entrylistmodel.h"

#include <QIcon>
#include <QPixmap>
#include <QDebug>
#include "../../../Common/enums.h"
#include "../../../Storage/persistentstorage_xml.h"
#include "../../../Common/tscore.h"
#include "../../../Common/helper.h"

EntryListModel::EntryListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    _storage = &TSCore::I().entriesStorage;//new PersistentStorage_XML();
}

int EntryListModel::rowCount(const QModelIndex& ) const
{
    return _storage->filteredEntries.size();
}

int EntryListModel::columnCount(const QModelIndex& ) const
{
    return 5;
}

QVariant EntryListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(role == Qt::EditRole)
    {
        Entry *e = _storage->entries.at(index.row());
        return e->title;
    }

    if(role == Qt::ToolTipRole)
    {
        Entry* e = _storage->filteredEntries.at(index.row());

        return QString("<b>Title:</b> %1<br/><b>Description:</b> %2")
                .arg(e->title)
                .arg(e->description);
    }

    if (role == Qt::DisplayRole){
       return QVariant();
    }

    if (role == Qt::WhatsThisRole){
        return _storage->filteredEntries.at(index.row())->toVariant();
    }

    else
        return QVariant();
}

QVariant EntryListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();

    if(orientation == Qt::Horizontal)
    {
        switch(section)
        {
        case 0:
            return ("Entry");

        default:
            return QVariant();
        }
    }
    else
    {
        return QString("Color %1").arg(section);
    }
}

void EntryListModel::insertEntry(Entry* e)
{
    int pocetPolozek = _storage->entries.size();
    beginInsertRows(QModelIndex(), pocetPolozek, pocetPolozek);

        _storage->entries.append(e);
        _storage->Save();
        _storage->Load();

    endInsertRows();
}


bool EntryListModel::insertRows(int position, int rows, const QModelIndex &index)
{
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for(int row = 0; row < rows; row++)
    {
        //entrie.insert(position, QColor(0, 0, 0, 255));
        Entry *e = new Entry();
        e->title = "new item";
        e->date = QDate::currentDate();
        e->from = Helper::RoundTimeUp(QTime::currentTime());
        e->to = Helper::RoundTimeUp(QTime::currentTime().addSecs(60*60*2));

        _storage->entries.append(e);
        _storage->Save();
        ApplyFilter();
    }

    endInsertRows();
    return true;
}

bool EntryListModel::removeRows(int position, int rows, const QModelIndex &index)
{
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for(int row = 0; row < rows; ++row)
    {
        Entry *eToRemove = _storage->filteredEntries.at(position);
        int index = _storage->entries.indexOf(eToRemove);

        _storage->entries.removeAt(index);
        delete eToRemove;

        _storage->Save();
        ApplyFilter();
    }

    endRemoveRows();
    return true;
}

bool EntryListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();

        Entry* eToEdit = _storage->filteredEntries.at(row);

        Entry::fromVariant(value, eToEdit);

        _storage->filteredEntries.replace(row, eToEdit);
        emit(dataChanged(index, index));

        return true;
    }

    return false;
}

Entry* EntryListModel::GetEntryAtIndex(const QModelIndex &index)
{
    if (index.isValid())
    {
        int row = index.row();
        if (row < _storage->filteredEntries.size())
        {
            Entry* eToReturn = _storage->filteredEntries.at(row);
            return eToReturn;
        }
    }

    return NULL;
}

Qt::ItemFlags EntryListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}


void EntryListModel::set_selected(QList<int>& rows){
    _selected_rows = rows;
    for(int i=0; i< _storage->filteredEntries.size(); i++){
        _storage->filteredEntries.at(i)->pl_selected = rows.contains(i);
    }
}

bool EntryListModel::is_selected(int row) const {
    return _selected_rows.contains(row);
}

void EntryListModel::ApplySearch(QString filter)
{
    QList<Entry*> fe = _storage->find(filter);

    beginInsertRows(QModelIndex(), 0, fe.size());
        _storage->filteredEntries.clear();
        _storage->filteredEntries = fe;
    endInsertRows();


}

void EntryListModel::ApplyFilter()
{
    ApplyFilter(fActive);
}

void EntryListModel::ApplyFilter(FilterBase* filter)
{
    fActive = filter;
    QList<Entry*> filtered = filter->apply(_storage->entries);

    beginInsertRows(QModelIndex(), 0, filtered.size());
        _storage->filteredEntries.clear();
        _storage->filteredEntries = filtered;
    endInsertRows();

}
