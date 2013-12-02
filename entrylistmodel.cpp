#include "entrylistmodel.h"

#include <QIcon>
#include <QPixmap>

EntryListModel::EntryListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

EntryListModel::EntryListModel(QList<Entry*> items, QObject* parent)
    : QAbstractListModel(parent)
{
    entries = items;
}

int EntryListModel::rowCount(const QModelIndex& ) const
{
    return entries.size();
}

QVariant EntryListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(role == Qt::DisplayRole)
    {
        //return "eee";
        return entries.at(index.row())->title;
    }

    if(role == Qt::DecorationRole)
    {
        int row = index.row();
        Entry *e = entries.value(row);
        QColor color = e->color;//colors.value(row);

        QPixmap pixmap(26, 26);
        pixmap.fill(color);

        QIcon icon(pixmap);

        return icon;
    }

    if(role == Qt::EditRole)
    {
        return entries.at(index.row())->title;
    }

    if(role == Qt::ToolTipRole)
    {
        return "Hex code: " + entries.at(index.row())->color.name();
    }

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
        eToEdit->title = value.toString();//"lll";//value.value<Entry*>;
        //eToEdit->title =  static_cast<QString>(value);

        //Entry *e = Entry(value.value<Entry*>());

        entries.replace(row, eToEdit);
        emit(dataChanged(index, index));

        return true;
    }

    return false;
}

Qt::ItemFlags EntryListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}
