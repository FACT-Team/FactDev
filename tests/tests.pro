include(../defaults.pri)

QT       -= gui

TARGET = tests

TEMPLATE = app

LIBS += -lgtest -lgtest_main -lpthread -L../src -lFactDev

HEADERS += \
    CustomTestPrinter.h

SOURCES += \
    test4.cpp \
    main.cpp \
    test5.cpp \
    test6.cpp \
    CustomTestPrinter.cpp
