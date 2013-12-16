#-------------------------------------------------
#
# Project created by QtCreator 2013-11-30T13:05:52
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += %mysql%/include
LIBS        += "c:\Program Files\MariaDB 10.0\lib\libmysql.lib"


TARGET = Timesheet
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    entrylistmodel.cpp \
    Data/entry.cpp \
    Data/tsproject.cpp \
    Data/tsfile.cpp \
    Managers/compmanager.cpp \
    Managers/entrymanager.cpp \
    Managers/tsmanager.cpp \
    Managers/tsprojectmanager.cpp \
    Managers/dbmanager.cpp

HEADERS  += dialog.h \
    entrylistmodel.h \
    Data/entry.h \
    Data/tsproject.h \
    Data/tsfile.h \
    Managers/compmanager.h \
    Managers/entrymanager.h \
    Managers/tsmanager.h \
    Managers/tsprojectmanager.h \
    Managers/dbmanager.h

FORMS    += dialog.ui
