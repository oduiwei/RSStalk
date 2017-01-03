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
    form.cpp \
    irc_window.cpp \
    create_channel.cpp \
    find_channel.cpp \
    emoji.cpp \
    channel.cpp \
    user.cpp \
    channel_user.cpp \
    feedback.cpp \
    join_channel.cpp \
    filedownloader.cpp \
    xmlinfodialog.cpp \
    multidownloader.cpp \
    activitydialog.cpp \
    searchtexttool.cpp \
    articleuiform.cpp

HEADERS  += mainwindow.h \
    feed.h \
    rss.h \
    atom.h \
    mylineedit.h \
    dbmanager.h \
    updatethread.h \
    form.h \
    irc_window.h \
    create_channel.h \
    find_channel.h \
    emoji.h \
    channel.h \
    user.h \
    channel_user.h \
    feedback.h \
    join_channel.h \
     filedownloader.h \
    xmlinfodialog.h \
    multidownloader.h \
    activitydialog.h \
    searchtexttool.h \
    articleuiform.h

FORMS    += mainwindow.ui \
    addfolder.ui \
    renamedialog.ui \
    form.ui \
    irc_window.ui \
    create_channel.ui \
    find_channel.ui \
    emoji.ui \
    feedback.ui \
    join_channel.ui \
    xmlinfodialog.ui \
    activitydialog.ui \
    articleuiform.ui

RESOURCES += \
    img.qrc

RC_FILE +=  icon.rc

