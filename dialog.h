#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QStandardItemModel>
#include "Managers/tsmanager.h"
#include "GUI/entry/model/entrylistmodel.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void Save();

    
private slots:
    void on_listView_clicked(const QModelIndex &index);
    void on_titleChanged(QString changedText);

private:
    Ui::Dialog *ui;
    EntryListModel *model;
    TSManager* manager;

};

#endif // DIALOG_H
