#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QString>
#include <QStandardItemModel>
#include <QTimer>

#include "Managers/tsmanager.h"
#include "GUI/entry/model/entrylistmodel.h"
#include "Common/tscore.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listView_clicked(const QModelIndex &index);

    void on_titleChanged(QString changedText);
    void on_toChanged(QString changedText);
    void on_fromChanged(QString changedText);
    void on_dateChanged(QString changedText);
    void on_descriptionChanged();
    void on_currentTextChanged(QString newText);

    void on_actionSmall_items_triggered(bool checked);

    void on_actionHighlight_today_entries_triggered(bool checked);

    void on_actionSelect_different_month_triggered();

    void UpdateStatusBar();
    void Refresh(QString finalFilter);


    void on_actionGo_back_to_current_month_triggered();

    void on_actionNext_month_triggered();

    void on_actionPrevious_month_triggered();

    void on_timeout();

    void on_actionCreate_desktop_file_triggered();
    void on_filteredTextChnged(QString changedText);


private:
    Ui::MainWindow *ui;
    TSManager* manager;
    QTimer* timer;
};

#endif // MAINWINDOW_H
