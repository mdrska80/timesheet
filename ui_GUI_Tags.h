/********************************************************************************
** Form generated from reading UI file 'GUI_Tags.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_TAGS_H
#define UI_GUI_TAGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI_Tags
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *GUI_Tags)
    {
        if (GUI_Tags->objectName().isEmpty())
            GUI_Tags->setObjectName(QStringLiteral("GUI_Tags"));
        GUI_Tags->resize(400, 300);
        horizontalLayout = new QHBoxLayout(GUI_Tags);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        retranslateUi(GUI_Tags);

        QMetaObject::connectSlotsByName(GUI_Tags);
    } // setupUi

    void retranslateUi(QWidget *GUI_Tags)
    {
        GUI_Tags->setWindowTitle(QApplication::translate("GUI_Tags", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI_Tags: public Ui_GUI_Tags {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_TAGS_H
