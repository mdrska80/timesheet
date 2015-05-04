/********************************************************************************
** Form generated from reading UI file 'GUI_Tag.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_TAG_H
#define UI_GUI_TAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI_Tag
{
public:
    QGridLayout *gridLayout;
    QLabel *lbl;

    void setupUi(QWidget *GUI_Tag)
    {
        if (GUI_Tag->objectName().isEmpty())
            GUI_Tag->setObjectName(QStringLiteral("GUI_Tag"));
        GUI_Tag->resize(317, 16);
        gridLayout = new QGridLayout(GUI_Tag);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lbl = new QLabel(GUI_Tag);
        lbl->setObjectName(QStringLiteral("lbl"));
        lbl->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbl, 0, 0, 1, 1);


        retranslateUi(GUI_Tag);

        QMetaObject::connectSlotsByName(GUI_Tag);
    } // setupUi

    void retranslateUi(QWidget *GUI_Tag)
    {
        GUI_Tag->setWindowTitle(QApplication::translate("GUI_Tag", "Form", 0));
        lbl->setText(QApplication::translate("GUI_Tag", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI_Tag: public Ui_GUI_Tag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_TAG_H
