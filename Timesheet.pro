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
    Data/tsfile.cpp \
    Managers/compmanager.cpp \
    Managers/entrymanager.cpp \
    Managers/tsmanager.cpp \
    Managers/tsprojectmanager.cpp \
    Managers/imanager.cpp

HEADERS  += dialog.h \
    timesheetlist.h \
    entrylistmodel.h \
    Data/entry.h \
    Data/tsproject.h \
    Data/tsfile.h \
    Managers/compmanager.h \
    Managers/entrymanager.h \
    Managers/tsmanager.h \
    Managers/tsprojectmanager.h \
    Managers/imanager.h

FORMS    += dialog.ui
