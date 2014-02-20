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
    Storage/persistentstorage_xml.cpp \
    Data/project.cpp \
    mainwindow.cpp \
    GUI/xmlFileDetail/delegate/xmlfiledetaildelegate.cpp \
    GUI/xmlFileDetail/entry/gui_xmlfiledetailentry.cpp \
    GUI/xmlFileDetail/entry/gui_xmlfiledetailentrybig.cpp \
    GUI/xmlFileDetail/model/xmlfiledetailmodel.cpp \
    Data/entryfileinfo.cpp \
    Data/errormessage.cpp \
    Storage/fileinfostorage.cpp \
    GUI/xmlFileDetail/view/xmlfiledetailview.cpp \
    dialogtester.cpp \
    Common/entriesanalyzer.cpp \
    Common/tscore.cpp \
    Filters/filterbase.cpp \
    Filters/filter_today.cpp \
    Filters/filter_valid.cpp \
    Filters/filter_invalid.cpp \
    Filters/filter_yesterday.cpp \
    Filters/filter_thisweek.cpp \
    Filters/filter_all.cpp \
    GUI/GUI_LevelPainter.cpp \
    GUI/GUI_Spectrum.cpp \
    GUI/EngineColorStyleChooser.cpp \
    Data/tag.cpp \
    Data/aggregatedentry.cpp \
    GUI/GUI_Tag.cpp \
    Data/attachment.cpp \
    GUI/GUI_Tags.cpp \
    exportdialog.cpp \
    Data/bustecdochazka.cpp \
    Data/bustecentry.cpp

HEADERS  += \
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
    Storage/persistentstorage_xml.h \
    Data/project.h \
    Common/enums.h \
    mainwindow.h \
    GUI/xmlFileDetail/delegate/xmlfiledetaildelegate.h \
    GUI/xmlFileDetail/entry/gui_xmlfiledetailentry.h \
    GUI/xmlFileDetail/entry/gui_xmlfiledetailentrybig.h \
    Data/entryfileinfo.h \
    Data/errormessage.h \
    GUI/xmlFileDetail/model/xmlfiledetailmodel.h \
    Storage/fileinfostorage.h \
    GUI/xmlFileDetail/view/xmlfiledetailview.h \
    dialogtester.h \
    Common/entriesanalyzer.h \
    Common/tscore.h \
    Filters/filterbase.h \
    Filters/filter_today.h \
    Filters/filter_valid.h \
    Filters/filter_invalid.h \
    Filters/filter_yesterday.h \
    Filters/filter_thisweek.h \
    Filters/filter_all.h \
    GUI/GUI_LevelPainter.h \
    GUI/GUI_Spectrum.h \
    GUI/StyleTypes.h \
    GUI/EngineColorStyleChooser.h \
    Data/tag.h \
    Data/aggregatedentry.h \
    GUI/GUI_Tag.h \
    Data/attachment.h \
    GUI/GUI_Tags.h \
    exportdialog.h \
    Data/bustecdochazka.h \
    Data/bustecentry.h

FORMS    += \
    GUI/entry/entry/gui_entryentrysmall.ui \
    GUI/entry/entry/gui_entryentrybig.ui \
    mainwindow.ui \
    GUI/xmlFileDetail/entry/gui_xmlfiledetailentrybig.ui \
    dialogtester.ui \
    GUI/GUI_LevelPainter.ui \
    GUI/GUI_Spectrum.ui \
    GUI/GUI_Tag.ui \
    GUI/GUI_Tags.ui \
    exportdialog.ui

RESOURCES += \
    resources.qrc
