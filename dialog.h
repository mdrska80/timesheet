#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QStandardItemModel>
#include "Managers/tsmanager.h"
#include "entrylistmodel.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::Dialog *ui;
    EntryListModel *model;
    TSManager* manager;

};

#endif // DIALOG_H
