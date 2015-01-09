#-------------------------------------------------
#
# Project created by QtCreator 2015-01-09T19:20:33
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_teststest
CONFIG   += testcase
CONFIG   -= app_bundle
LIBS += -lUnitTest++
TEMPLATE = app

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS +=

SOURCES += \
    test.cpp \
    test2.cpp \
    test3.cpp

