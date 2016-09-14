#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T09:32:57
#
#-------------------------------------------------

QT       += core gui
QT += webenginewidgets
QT += xml
QT += network
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RSStalk
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    feed.cpp \
    rss.cpp \
    atom.cpp \
    feedlist.cpp \
    folderlistmanager.cpp \
    mylineedit.cpp \
    dbmanager.cpp \
    updatethread.cpp

HEADERS  += mainwindow.h \
    feed.h \
    rss.h \
    atom.h \
    feedlist.h \
    folderlistmanager.h \
    mylineedit.h \
    dbmanager.h \
    updatethread.h

FORMS    += mainwindow.ui \
    addfolder.ui \
    renamedialog.ui

RESOURCES += \
    img.qrc \
    xmlfile.qrc

RC_FILE +=  icon.rc

