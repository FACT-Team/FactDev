include(../defaults.pri)

QT       -= gui
CONFIG += qtestlib

TARGET = tests

TEMPLATE = app

LIBS += -L../src -lFactDev

HEADERS += \
    #CustomTestPrinter.h
    testqstring.h

SOURCES += \
    main.cpp \
  #  CustomTestPrinter.cpp \
   # database/customerdatabasetest.cpp
    testqstring.cpp
