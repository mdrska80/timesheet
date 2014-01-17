#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QStandardItemModel>
#include <QMenuBar>
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
    void HandleMenu(QWidget *parent);

    
private slots:
    void on_listView_clicked(const QModelIndex &index);

    void on_titleChanged(QString changedText);
    void on_toChanged(QString changedText);
    void on_fromChanged(QString changedText);
    void on_dateChanged(QString changedText);
    void on_descriptionChanged();
    void on_currentTextChanged(QString newText);

private:
    Ui::Dialog *ui;
    //EntryListModel *model;
    TSManager* manager;

    QMenuBar *menubar;
    QMenu *menuFle;
    QMenu *menuView;
    QMenu *menuPreferences;
    QMenu *menuAbout;
};

#endif // DIALOG_H
