#-------------------------------------------------
#
# Project created by QtCreator 2013-11-30T13:05:52
#
#-------------------------------------------------

QT       += core gui sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Timesheet
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    GUI/entry/model/entrylistmodel.cpp \
    Data/entry.cpp \
    Data/tsfile.cpp \
    Managers/compmanager.cpp \
    Managers/entrymanager.cpp \
    Managers/tsmanager.cpp \
    Managers/dbmanager.cpp \
    Data/company.cpp \
    Common/helper.cpp \
    Common/style.cpp \
    GUI/entry/delegate/entryitemdelegate.cpp \
    GUI/entry/entry/gui_entryentry.cpp \
    GUI/entry/entry/gui_entryentrysmall.cpp \
    GUI/entry/entry/gui_entryentrybig.cpp \
    GUI/entry/view/entrylistview.cpp \
    Common/qtimespan.cpp \
    Storage/persistentstorage_xml.cpp \
    Data/project.cpp

HEADERS  += dialog.h \
    GUI/entry/model/entrylistmodel.h \
    Data/entry.h \
    Data/tsfile.h \
    Managers/compmanager.h \
    Managers/entrymanager.h \
    Managers/tsmanager.h \
    Managers/dbmanager.h \
    Data/company.h \
    Common/helper.h \
    Common/style.h \
    GUI/entry/delegate/entryitemdelegate.h \
    GUI/entry/entry/gui_entryentry.h \
    GUI/entry/entry/gui_entryentrysmall.h \
    GUI/entry/entry/gui_entryentrybig.h \
    GUI/entry/view/entrylistview.h \
    Common/qtimespan.h \
    Storage/persistentstorage_xml.h \
    Data/project.h \
    Common/enums.h

FORMS    += dialog.ui \
    GUI/entry/entry/gui_entryentrysmall.ui \
    GUI/entry/entry/gui_entryentrybig.ui

RESOURCES += \
    resources.qrc
