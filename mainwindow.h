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

#include "Filters/filter_today.h"
#include "Filters/filter_valid.h"
#include "Filters/filter_invalid.h"
#include "Filters/filter_yesterday.h"
#include "Filters/filter_thisweek.h"
#include "Filters/filter_all.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void HandleFilters();


private slots:
    void on_listView_clicked(const QModelIndex &index);

    void on_titleChanged(QString changedText);
    void on_toChanged(QString changedText);
    void on_fromChanged(QString changedText);
    void on_dateChanged(QString changedText);
    void on_descriptionChanged();
    void on_currentTextChanged(QString newText);

    void on_actionSmall_items_triggered(bool checked);


    void on_actionSelect_different_month_triggered();

    void UpdateStatusBar();
    void Refresh(QString finalFilter);


    void on_actionGo_back_to_current_month_triggered();

    void on_actionNext_month_triggered();

    void on_actionPrevious_month_triggered();

    void on_timeout();

    void on_actionCreate_desktop_file_triggered();
    void on_filteredTextChnged(QString changedText);


    void on_actionExit_triggered();

    void on_actionMonthly_triggered();

    void on_actionShow_spectrum_triggered(bool checked);

private:
    Ui::MainWindow *ui;
    TSManager* manager;
    QTimer* timer;

    QHash<QString, FilterBase*> filters;

    Filter_Today* ft;
    Filter_Valid* fv;
    Filter_Invalid* fiv;
    Filter_Yesterday* fy;
    Filter_Thisweek* ftw;
    Filter_All* fa;
};

#endif // MAINWINDOW_H
