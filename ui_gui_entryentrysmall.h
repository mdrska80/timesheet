/********************************************************************************
** Form generated from reading UI file 'gui_entryentrysmall.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_ENTRYENTRYSMALL_H
#define UI_GUI_ENTRYENTRYSMALL_H

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

class Ui_GUI_EntryEntrySmall
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *dayLabel;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *fromToLabel;
    QLabel *durationLabel;

    void setupUi(QFrame *GUI_EntryEntrySmall)
    {
        if (GUI_EntryEntrySmall->objectName().isEmpty())
            GUI_EntryEntrySmall->setObjectName(QStringLiteral("GUI_EntryEntrySmall"));
        GUI_EntryEntrySmall->resize(385, 22);
        GUI_EntryEntrySmall->setStyleSheet(QStringLiteral("background: transparent;"));
        GUI_EntryEntrySmall->setFrameShape(QFrame::StyledPanel);
        GUI_EntryEntrySmall->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(GUI_EntryEntrySmall);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 22, 0);
        dayLabel = new QLabel(GUI_EntryEntrySmall);
        dayLabel->setObjectName(QStringLiteral("dayLabel"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        dayLabel->setFont(font);

        horizontalLayout->addWidget(dayLabel);

        titleLabel = new QLabel(GUI_EntryEntrySmall);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        titleLabel->setFont(font1);

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        fromToLabel = new QLabel(GUI_EntryEntrySmall);
        fromToLabel->setObjectName(QStringLiteral("fromToLabel"));
        QFont font2;
        font2.setPointSize(8);
        fromToLabel->setFont(font2);

        horizontalLayout->addWidget(fromToLabel);

        durationLabel = new QLabel(GUI_EntryEntrySmall);
        durationLabel->setObjectName(QStringLiteral("durationLabel"));
        durationLabel->setFont(font1);

        horizontalLayout->addWidget(durationLabel);


        retranslateUi(GUI_EntryEntrySmall);

        QMetaObject::connectSlotsByName(GUI_EntryEntrySmall);
    } // setupUi

    void retranslateUi(QFrame *GUI_EntryEntrySmall)
    {
        GUI_EntryEntrySmall->setWindowTitle(QApplication::translate("GUI_EntryEntrySmall", "Frame", 0));
        dayLabel->setText(QApplication::translate("GUI_EntryEntrySmall", "TextLabel", 0));
        titleLabel->setText(QApplication::translate("GUI_EntryEntrySmall", "TextLabel", 0));
        fromToLabel->setText(QApplication::translate("GUI_EntryEntrySmall", "TextLabel", 0));
        durationLabel->setText(QApplication::translate("GUI_EntryEntrySmall", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI_EntryEntrySmall: public Ui_GUI_EntryEntrySmall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_ENTRYENTRYSMALL_H
