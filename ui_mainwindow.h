/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "GUI/GUI_Spectrum.h"
#include "GUI/entry/view/entrylistview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSmall_items;
    QAction *actionHighlight_today_entries;
    QAction *actionSelect_different_month;
    QAction *actionExit;
    QAction *actionGo_back_to_current_month;
    QAction *actionNext_month;
    QAction *actionPrevious_month;
    QAction *actionCreate_desktop_file;
    QAction *actionMonthly;
    QAction *actionShow_spectrum;
    QAction *actionExport;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_Controls;
    QVBoxLayout *verticalLayout_Controls;
    QHBoxLayout *horizontalLayout_Data;
    QLabel *label;
    QLineEdit *dateLineEdit;
    QLineEdit *fromLineEdit;
    QLineEdit *toLineEdit;
    QLineEdit *overtimeLineEdit;
    QSpacerItem *horizontalSpacer;
    QLineEdit *filterLineEdit;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_Title;
    QLineEdit *titleLineEdit;
    QLabel *urlLabel;
    QTextEdit *descriptionTextEdit;
    GUI_Spectrum *spectrum;
    EntryListView *listView;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuTools;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(876, 600);
        actionSmall_items = new QAction(MainWindow);
        actionSmall_items->setObjectName(QStringLiteral("actionSmall_items"));
        actionSmall_items->setCheckable(true);
        actionHighlight_today_entries = new QAction(MainWindow);
        actionHighlight_today_entries->setObjectName(QStringLiteral("actionHighlight_today_entries"));
        actionHighlight_today_entries->setCheckable(true);
        actionHighlight_today_entries->setChecked(true);
        actionSelect_different_month = new QAction(MainWindow);
        actionSelect_different_month->setObjectName(QStringLiteral("actionSelect_different_month"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon;
        icon.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        actionGo_back_to_current_month = new QAction(MainWindow);
        actionGo_back_to_current_month->setObjectName(QStringLiteral("actionGo_back_to_current_month"));
        actionNext_month = new QAction(MainWindow);
        actionNext_month->setObjectName(QStringLiteral("actionNext_month"));
        actionPrevious_month = new QAction(MainWindow);
        actionPrevious_month->setObjectName(QStringLiteral("actionPrevious_month"));
        actionCreate_desktop_file = new QAction(MainWindow);
        actionCreate_desktop_file->setObjectName(QStringLiteral("actionCreate_desktop_file"));
        actionMonthly = new QAction(MainWindow);
        actionMonthly->setObjectName(QStringLiteral("actionMonthly"));
        actionShow_spectrum = new QAction(MainWindow);
        actionShow_spectrum->setObjectName(QStringLiteral("actionShow_spectrum"));
        actionShow_spectrum->setCheckable(true);
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_Controls = new QHBoxLayout();
        horizontalLayout_Controls->setObjectName(QStringLiteral("horizontalLayout_Controls"));
        verticalLayout_Controls = new QVBoxLayout();
        verticalLayout_Controls->setObjectName(QStringLiteral("verticalLayout_Controls"));
        horizontalLayout_Data = new QHBoxLayout();
        horizontalLayout_Data->setObjectName(QStringLiteral("horizontalLayout_Data"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_Data->addWidget(label);

        dateLineEdit = new QLineEdit(centralwidget);
        dateLineEdit->setObjectName(QStringLiteral("dateLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dateLineEdit->sizePolicy().hasHeightForWidth());
        dateLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_Data->addWidget(dateLineEdit);

        fromLineEdit = new QLineEdit(centralwidget);
        fromLineEdit->setObjectName(QStringLiteral("fromLineEdit"));

        horizontalLayout_Data->addWidget(fromLineEdit);

        toLineEdit = new QLineEdit(centralwidget);
        toLineEdit->setObjectName(QStringLiteral("toLineEdit"));
        sizePolicy.setHeightForWidth(toLineEdit->sizePolicy().hasHeightForWidth());
        toLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_Data->addWidget(toLineEdit);

        overtimeLineEdit = new QLineEdit(centralwidget);
        overtimeLineEdit->setObjectName(QStringLiteral("overtimeLineEdit"));

        horizontalLayout_Data->addWidget(overtimeLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Data->addItem(horizontalSpacer);

        filterLineEdit = new QLineEdit(centralwidget);
        filterLineEdit->setObjectName(QStringLiteral("filterLineEdit"));

        horizontalLayout_Data->addWidget(filterLineEdit);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(120, 0));

        horizontalLayout_Data->addWidget(comboBox);


        verticalLayout_Controls->addLayout(horizontalLayout_Data);

        horizontalLayout_Title = new QHBoxLayout();
        horizontalLayout_Title->setObjectName(QStringLiteral("horizontalLayout_Title"));
        titleLineEdit = new QLineEdit(centralwidget);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));

        horizontalLayout_Title->addWidget(titleLineEdit);

        urlLabel = new QLabel(centralwidget);
        urlLabel->setObjectName(QStringLiteral("urlLabel"));

        horizontalLayout_Title->addWidget(urlLabel);


        verticalLayout_Controls->addLayout(horizontalLayout_Title);

        descriptionTextEdit = new QTextEdit(centralwidget);
        descriptionTextEdit->setObjectName(QStringLiteral("descriptionTextEdit"));
        descriptionTextEdit->setMaximumSize(QSize(16777215, 150));
        descriptionTextEdit->setTabChangesFocus(true);

        verticalLayout_Controls->addWidget(descriptionTextEdit);


        horizontalLayout_Controls->addLayout(verticalLayout_Controls);

        spectrum = new GUI_Spectrum(centralwidget);
        spectrum->setObjectName(QStringLiteral("spectrum"));
        spectrum->setMinimumSize(QSize(200, 10));

        horizontalLayout_Controls->addWidget(spectrum);


        verticalLayout->addLayout(horizontalLayout_Controls);

        listView = new EntryListView(centralwidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setAutoFillBackground(true);
        listView->setAlternatingRowColors(true);

        verticalLayout->addWidget(listView);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 876, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuTools->menuAction());
        menuFile->addAction(actionExit);
        menuView->addAction(actionSmall_items);
        menuView->addAction(actionHighlight_today_entries);
        menuView->addAction(actionShow_spectrum);
        menuView->addSeparator();
        menuView->addAction(actionSelect_different_month);
        menuView->addAction(actionGo_back_to_current_month);
        menuView->addAction(actionNext_month);
        menuView->addAction(actionPrevious_month);
        menuTools->addAction(actionCreate_desktop_file);
        menuTools->addAction(actionExport);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Timesheet", 0));
        actionSmall_items->setText(QApplication::translate("MainWindow", "Small items", 0));
        actionHighlight_today_entries->setText(QApplication::translate("MainWindow", "Highlight today entries", 0));
        actionSelect_different_month->setText(QApplication::translate("MainWindow", "Select different month", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionGo_back_to_current_month->setText(QApplication::translate("MainWindow", "Go back to current month", 0));
        actionNext_month->setText(QApplication::translate("MainWindow", "Next month", 0));
        actionNext_month->setShortcut(QApplication::translate("MainWindow", "Ctrl+Right", 0));
        actionPrevious_month->setText(QApplication::translate("MainWindow", "Previous month", 0));
        actionPrevious_month->setShortcut(QApplication::translate("MainWindow", "Ctrl+Left", 0));
        actionCreate_desktop_file->setText(QApplication::translate("MainWindow", "Create .desktop file", 0));
        actionMonthly->setText(QApplication::translate("MainWindow", "Monthly", 0));
        actionShow_spectrum->setText(QApplication::translate("MainWindow", "Show spectrum", 0));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0));
        label->setText(QApplication::translate("MainWindow", "<b>Date:</b>", 0));
        fromLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "od", 0));
        toLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "do", 0));
#ifndef QT_NO_STATUSTIP
        overtimeLineEdit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        overtimeLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "P\305\231es\304\215as po p\305\257lnoci", 0));
        urlLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
