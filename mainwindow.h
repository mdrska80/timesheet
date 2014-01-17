#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStandardItemModel>
#include "Managers/tsmanager.h"
#include "GUI/entry/model/entrylistmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void HandleMenu(QWidget *parent);


private slots:
    void on_listView_clicked(const QModelIndex &index);

    void on_titleChanged();
    void on_toChanged(QString changedText);
    void on_fromChanged(QString changedText);
    void on_dateChanged(QString changedText);
    void on_descriptionChanged();
    void on_currentTextChanged(QString newText);

    void on_actionSmall_items_triggered(bool checked);

    void on_actionHighlight_today_entries_triggered(bool checked);

private:
    Ui::MainWindow *ui;
    TSManager* manager;
};

#endif // MAINWINDOW_H
