/********************************************************************************
** Form generated from reading UI file 'GUI_LevelPainter.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_LEVELPAINTER_H
#define UI_GUI_LEVELPAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI_LevelPainter
{
public:
    QGridLayout *gridLayout;
    QLabel *lab;

    void setupUi(QWidget *GUI_LevelPainter)
    {
        if (GUI_LevelPainter->objectName().isEmpty())
            GUI_LevelPainter->setObjectName(QStringLiteral("GUI_LevelPainter"));
        GUI_LevelPainter->resize(340, 40);
        GUI_LevelPainter->setMinimumSize(QSize(0, 40));
        GUI_LevelPainter->setMaximumSize(QSize(16777215, 40));
        gridLayout = new QGridLayout(GUI_LevelPainter);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lab = new QLabel(GUI_LevelPainter);
        lab->setObjectName(QStringLiteral("lab"));
        lab->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lab, 0, 0, 1, 1);


        retranslateUi(GUI_LevelPainter);

        QMetaObject::connectSlotsByName(GUI_LevelPainter);
    } // setupUi

    void retranslateUi(QWidget *GUI_LevelPainter)
    {
        GUI_LevelPainter->setWindowTitle(QApplication::translate("GUI_LevelPainter", "Form", 0));
        lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GUI_LevelPainter: public Ui_GUI_LevelPainter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_LEVELPAINTER_H
