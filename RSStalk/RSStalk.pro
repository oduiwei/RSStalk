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
    mylineedit.cpp \
    dbmanager.cpp \
    updatethread.cpp \
    filedownloader.cpp \
    xmlinfodialog.cpp \
    multidownloader.cpp

HEADERS  += mainwindow.h \
    feed.h \
    rss.h \
    atom.h \
    mylineedit.h \
    dbmanager.h \
    updatethread.h \
    filedownloader.h \
    xmlinfodialog.h \
    multidownloader.h

FORMS    += mainwindow.ui \
    addfolder.ui \
    renamedialog.ui \
    xmlinfodialog.ui

RESOURCES += \
    img.qrc

RC_FILE +=  icon.rc

