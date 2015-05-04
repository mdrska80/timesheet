/********************************************************************************
** Form generated from reading UI file 'gui_xmlfiledetailentrybig.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_XMLFILEDETAILENTRYBIG_H
#define UI_GUI_XMLFILEDETAILENTRYBIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_GUI_XmlFileDetailEntryBig
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *imageLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *monthLabel;
    QLabel *yearLabel;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *percentLabel;

    void setupUi(QFrame *GUI_XmlFileDetailEntryBig)
    {
        if (GUI_XmlFileDetailEntryBig->objectName().isEmpty())
            GUI_XmlFileDetailEntryBig->setObjectName(QStringLiteral("GUI_XmlFileDetailEntryBig"));
        GUI_XmlFileDetailEntryBig->resize(400, 26);
        GUI_XmlFileDetailEntryBig->setFrameShape(QFrame::StyledPanel);
        GUI_XmlFileDetailEntryBig->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(GUI_XmlFileDetailEntryBig);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 2, -1, 2);
        imageLabel = new QLabel(GUI_XmlFileDetailEntryBig);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));

        horizontalLayout->addWidget(imageLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        monthLabel = new QLabel(GUI_XmlFileDetailEntryBig);
        monthLabel->setObjectName(QStringLiteral("monthLabel"));
        monthLabel->setMaximumSize(QSize(50, 16777215));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        monthLabel->setFont(font);

        horizontalLayout_2->addWidget(monthLabel);

        yearLabel = new QLabel(GUI_XmlFileDetailEntryBig);
        yearLabel->setObjectName(QStringLiteral("yearLabel"));
        yearLabel->setMaximumSize(QSize(50, 16777215));
        QFont font1;
        font1.setPointSize(8);
        yearLabel->setFont(font1);

        horizontalLayout_2->addWidget(yearLabel);


        horizontalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(GUI_XmlFileDetailEntryBig);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        percentLabel = new QLabel(GUI_XmlFileDetailEntryBig);
        percentLabel->setObjectName(QStringLiteral("percentLabel"));
        percentLabel->setFont(font);

        horizontalLayout->addWidget(percentLabel);


        retranslateUi(GUI_XmlFileDetailEntryBig);

        QMetaObject::connectSlotsByName(GUI_XmlFileDetailEntryBig);
    } // setupUi

    void retranslateUi(QFrame *GUI_XmlFileDetailEntryBig)
    {
        GUI_XmlFileDetailEntryBig->setWindowTitle(QApplication::translate("GUI_XmlFileDetailEntryBig", "Frame", 0));
        imageLabel->setText(QApplication::translate("GUI_XmlFileDetailEntryBig", "TextLabel", 0));
        monthLabel->setText(QApplication::translate("GUI_XmlFileDetailEntryBig", "<center>XX</center>", 0));
        yearLabel->setText(QApplication::translate("GUI_XmlFileDetailEntryBig", "<center>YYYY</center>", 0));
        label_2->setText(QApplication::translate("GUI_XmlFileDetailEntryBig", "XY entries - 140h / 200h", 0));
        percentLabel->setText(QApplication::translate("GUI_XmlFileDetailEntryBig", "82%", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI_XmlFileDetailEntryBig: public Ui_GUI_XmlFileDetailEntryBig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_XMLFILEDETAILENTRYBIG_H
