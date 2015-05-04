/********************************************************************************
** Form generated from reading UI file 'gui_entryentrybig.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_ENTRYENTRYBIG_H
#define UI_GUI_ENTRYENTRYBIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "GUI/GUI_LevelPainter.h"
#include "GUI/GUI_Tags.h"

QT_BEGIN_NAMESPACE

class Ui_GUI_EntryEntryBig
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *dayLabel;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *descriptionLabel;
    QSpacerItem *horizontalSpacer;
    GUI_Tags *tag;
    QLabel *urlImageLabel;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *fromLabel;
    GUI_LevelPainter *levels;
    QLabel *durationLabel;

    void setupUi(QFrame *GUI_EntryEntryBig)
    {
        if (GUI_EntryEntryBig->objectName().isEmpty())
            GUI_EntryEntryBig->setObjectName(QStringLiteral("GUI_EntryEntryBig"));
        GUI_EntryEntryBig->resize(451, 44);
        GUI_EntryEntryBig->setFrameShape(QFrame::StyledPanel);
        GUI_EntryEntryBig->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(GUI_EntryEntryBig);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 3, 22, 3);
        dayLabel = new QLabel(GUI_EntryEntryBig);
        dayLabel->setObjectName(QStringLiteral("dayLabel"));
        QFont font;
        font.setPointSize(12);
        dayLabel->setFont(font);

        horizontalLayout->addWidget(dayLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 3, -1, 0);
        titleLabel = new QLabel(GUI_EntryEntryBig);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        titleLabel->setFont(font1);

        verticalLayout->addWidget(titleLabel);

        descriptionLabel = new QLabel(GUI_EntryEntryBig);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
        QFont font2;
        font2.setPointSize(9);
        font2.setItalic(true);
        font2.setStyleStrategy(QFont::PreferAntialias);
        descriptionLabel->setFont(font2);

        verticalLayout->addWidget(descriptionLabel);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tag = new GUI_Tags(GUI_EntryEntryBig);
        tag->setObjectName(QStringLiteral("tag"));
        tag->setMinimumSize(QSize(0, 10));

        horizontalLayout->addWidget(tag);

        urlImageLabel = new QLabel(GUI_EntryEntryBig);
        urlImageLabel->setObjectName(QStringLiteral("urlImageLabel"));

        horizontalLayout->addWidget(urlImageLabel);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        fromLabel = new QLabel(GUI_EntryEntryBig);
        fromLabel->setObjectName(QStringLiteral("fromLabel"));
        QFont font3;
        font3.setPointSize(8);
        fromLabel->setFont(font3);

        horizontalLayout_2->addWidget(fromLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        levels = new GUI_LevelPainter(GUI_EntryEntryBig);
        levels->setObjectName(QStringLiteral("levels"));
        levels->setMinimumSize(QSize(0, 10));

        verticalLayout_2->addWidget(levels);


        horizontalLayout->addLayout(verticalLayout_2);

        durationLabel = new QLabel(GUI_EntryEntryBig);
        durationLabel->setObjectName(QStringLiteral("durationLabel"));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        durationLabel->setFont(font4);

        horizontalLayout->addWidget(durationLabel);


        retranslateUi(GUI_EntryEntryBig);

        QMetaObject::connectSlotsByName(GUI_EntryEntryBig);
    } // setupUi

    void retranslateUi(QFrame *GUI_EntryEntryBig)
    {
        GUI_EntryEntryBig->setWindowTitle(QApplication::translate("GUI_EntryEntryBig", "Frame", 0));
        dayLabel->setText(QApplication::translate("GUI_EntryEntryBig", "TextLabel", 0));
        titleLabel->setText(QApplication::translate("GUI_EntryEntryBig", "TextLabel", 0));
        descriptionLabel->setText(QApplication::translate("GUI_EntryEntryBig", "TextLabel", 0));
        urlImageLabel->setText(QApplication::translate("GUI_EntryEntryBig", "TextLabel", 0));
        fromLabel->setText(QApplication::translate("GUI_EntryEntryBig", "TextLabel", 0));
        durationLabel->setText(QApplication::translate("GUI_EntryEntryBig", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI_EntryEntryBig: public Ui_GUI_EntryEntryBig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_ENTRYENTRYBIG_H
