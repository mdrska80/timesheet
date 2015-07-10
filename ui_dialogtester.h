/********************************************************************************
** Form generated from reading UI file 'dialogtester.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTESTER_H
#define UI_DIALOGTESTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "GUI/xmlFileDetail/view/xmlfiledetailview.h"

QT_BEGIN_NAMESPACE

class Ui_DialogTester
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *filterLineEdit;
    XmlFileDetailView *listView;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogTester)
    {
        if (DialogTester->objectName().isEmpty())
            DialogTester->setObjectName(QStringLiteral("DialogTester"));
        DialogTester->setWindowModality(Qt::WindowModal);
        DialogTester->resize(400, 571);
        verticalLayout = new QVBoxLayout(DialogTester);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        filterLineEdit = new QLineEdit(DialogTester);
        filterLineEdit->setObjectName(QStringLiteral("filterLineEdit"));

        verticalLayout->addWidget(filterLineEdit);

        listView = new XmlFileDetailView(DialogTester);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);

        pushButton = new QPushButton(DialogTester);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(DialogTester);

        QMetaObject::connectSlotsByName(DialogTester);
    } // setupUi

    void retranslateUi(QDialog *DialogTester)
    {
        DialogTester->setWindowTitle(QApplication::translate("DialogTester", "Select timesheet file", 0));
        filterLineEdit->setPlaceholderText(QApplication::translate("DialogTester", "enter your filter data here", 0));
        pushButton->setText(QApplication::translate("DialogTester", "Select", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogTester: public Ui_DialogTester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTESTER_H
