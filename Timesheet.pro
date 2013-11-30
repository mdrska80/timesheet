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
    entry.cpp

HEADERS  += dialog.h \
    timesheetlist.h \
    entrylistmodel.h \
    entry.h

FORMS    += dialog.ui \
    timesheetlist.ui
