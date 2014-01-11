#include "entrylistmodel.h"

#include <QIcon>
#include <QPixmap>
#include <QDebug>
#include "Storage/persistentstorage_xml.h"

EntryListModel::EntryListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    _storage = new PersistentStorage_XML();
}

int EntryListModel::rowCount(const QModelIndex& ) const
{
    return entries.size();
}

int EntryListModel::columnCount(const QModelIndex& ) const
{
    return 5;
}

QVariant EntryListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    int row = index.row();
    int column = index.column();

//    if(role == Qt::DisplayRole)
//    {
//        Entry *e = entries.at(row);
//        return "<b>"+e->title + "</b>(Display)";
//    }

//    if(role == Qt::DecorationRole)
//    {
//        Entry *e = entries.value(row);
//        QColor color = e->color;//colors.value(row);

//        QPixmap pixmap(26, 26);
//        pixmap.fill(color);

//        QIcon icon(pixmap);

//        return icon;
//    }

    if(role == Qt::EditRole)
    {
//        return entries.at(index.row())->title;
        Entry *e = entries.at(index.row());
        return e->title;
    }

    if(role == Qt::ToolTipRole)
    {
        return "<b>Hex code:</b> " + entries.at(index.row())->color.name();
    }

    if (role == Qt::DisplayRole){
        //return entries[index.row()]->toVariant();
       return QVariant();
    }

    if (role == Qt::WhatsThisRole){
        return entries[index.row()]->toVariant();
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

bool EntryListModel::insertEntry(Entry* e)
{
    int pocetPolozek = entries.size();
    beginInsertRows(QModelIndex(), pocetPolozek, pocetPolozek);

        entries.append(e);
        _storage->Save(&entries);

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
        entries.insert(position, e);
    }

    endInsertRows();
    return true;
}

bool EntryListModel::removeRows(int position, int rows, const QModelIndex &index)
{
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for(int row = 0; row < rows; ++row)
    {
        entries.removeAt(position);
    }

    endRemoveRows();
    return true;
}

bool EntryListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();

        Entry* eToEdit = entries[row];

        Entry::fromVariant(value, eToEdit);

        //eToEdit->title = Entry::fromVariant(value.toString();



        //"lll";//value.value<Entry*>;
        //eToEdit->title =  static_cast<QString>(value);

        //Entry *e = Entry(value.value<Entry*>());

        entries.replace(row, eToEdit);
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
        if (row < entries.size())
        {
            Entry* eToReturn = entries[row];
            return eToReturn;
        }

        return NULL;

    }
}

Qt::ItemFlags EntryListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}


void EntryListModel::set_selected(QList<int>& rows){
    _selected_rows = rows;
    for(uint i=0; i< entries.size(); i++){
        entries[i]->pl_selected = rows.contains(i);
    }
}

bool EntryListModel::is_selected(int row) const {
    return _selected_rows.contains(row);
}
