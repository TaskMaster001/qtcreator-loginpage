#-------------------------------------------------
#
# Project created by QtCreator 2019-07-20T19:53:19
#
#-------------------------------------------------

QT       += core gui sql
Qt          += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DB
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    dialog.cpp

HEADERS  += login.h \
    dialog.h

FORMS    += login.ui \
    dialog.ui
