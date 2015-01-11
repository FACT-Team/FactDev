include(../defaults.pri)

QT       -= gui

TARGET = tests

TEMPLATE = app

LIBS += -lgtest -lgtest_main -lpthread -L../src -lFactDev

HEADERS += \
    CustomTestPrinter.h

SOURCES += \
    main.cpp \
    CustomTestPrinter.cpp \
    database/customerdatabasetest.cpp
