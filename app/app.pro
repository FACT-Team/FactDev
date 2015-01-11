include(../defaults.pri)

QT       +=  gui sql printsupport

CONFIG -= console
CONFIG += app_bundle
CONFIG += qt

TEMPLATE = app

SOURCES += main.cpp

LIBS += -L../src -lFactDev

