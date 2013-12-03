#-------------------------------------------------
#
# Project created by QtCreator 2013-11-30T13:05:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Timesheet
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    timesheetlist.cpp \
    entrylistmodel.cpp \
    Data/entry.cpp \
    Data/tsproject.cpp \
    Managers/compmanager.cpp \
    Managers/entrymanager.cpp \
    Managers/tsmanager.cpp \
    Managers/tsprojectmanager.cpp

HEADERS  += dialog.h \
    timesheetlist.h \
    entrylistmodel.h \
    Data/entry.h \
    Data/tsproject.h \
    Managers/compmanager.h \
    Managers/entrymanager.h \
    Managers/tsmanager.h \
    Managers/tsprojectmanager.h

FORMS    += dialog.ui
