include(../defaults.pri)

QT       -= gui
QT       += testlib sql printsupport

TARGET = tests
QMAKE_CXXFLAGS += -std=c++0x -fprofile-arcs -ftest-coverage
QMAKE_LDFLAGS += -fprofile-arcs -ftest-coverage

TEMPLATE = app
CONFIG += c++11
LIBS += -L../src -lFactDev -lgcov

HEADERS += \
    #CustomTestPrinter.h
database/customerdatabasetest.h \
    QTestRunner/testadder.h \
    QTestRunner/testrunner.h \
    models/customermodeltest.h \
    models/searchtest.h \
    database/billingdatabasetest.h \
    models/billingmodeltest.h \
    database/contributoriesdatabasetest.h

SOURCES += \
    QTestRunner/main.cpp \
database/customerdatabasetest.cpp \
    QTestRunner/testrunner.cpp \
    QTestRunner/testadder.cpp \
    models/customermodeltest.cpp \
    models/searchtest.cpp \
    database/billingdatabasetest.cpp \
    models/billingmodeltest.cpp \
    database/contributoriesdatabasetest.cpp
  #  CustomTestPrinter.cpp \
   # database/customerdatabasetest.cpp
