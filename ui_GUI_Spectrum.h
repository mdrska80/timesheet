/********************************************************************************
** Form generated from reading UI file 'GUI_Spectrum.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_SPECTRUM_H
#define UI_GUI_SPECTRUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI_Spectrum
{
public:
    QGridLayout *gridLayout;
    QLabel *lab;

    void setupUi(QWidget *GUI_Spectrum)
    {
        if (GUI_Spectrum->objectName().isEmpty())
            GUI_Spectrum->setObjectName(QStringLiteral("GUI_Spectrum"));
        GUI_Spectrum->resize(479, 150);
        GUI_Spectrum->setMinimumSize(QSize(0, 150));
        GUI_Spectrum->setMaximumSize(QSize(16777215, 150));
        gridLayout = new QGridLayout(GUI_Spectrum);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, -1, 0, -1);
        lab = new QLabel(GUI_Spectrum);
        lab->setObjectName(QStringLiteral("lab"));
        lab->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lab, 0, 0, 1, 1);


        retranslateUi(GUI_Spectrum);

        QMetaObject::connectSlotsByName(GUI_Spectrum);
    } // setupUi

    void retranslateUi(QWidget *GUI_Spectrum)
    {
        GUI_Spectrum->setWindowTitle(QApplication::translate("GUI_Spectrum", "Form", 0));
        lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GUI_Spectrum: public Ui_GUI_Spectrum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_SPECTRUM_H
