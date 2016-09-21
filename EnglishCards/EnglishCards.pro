#-------------------------------------------------
#
# Project created by QtCreator 2016-09-21T17:09:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EnglishCards
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    card.cpp

HEADERS  += mainwindow.h \
    card.h

FORMS    += mainwindow.ui
