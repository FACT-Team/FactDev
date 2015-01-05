#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T13:44:51
#
#-------------------------------------------------

QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FactDev
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        log.cpp\
        # Database files
        database/database.cpp \
        # Exceptions
        exceptions/dbexception.cpp \
        models/client.cpp \
        parameters.cpp \
        dialogaddclient.cpp

HEADERS  += mainwindow.h \
        log.h\
        dialogaddclient.h \
        # Database files
        database/database.h \
        #Exceptions
        exceptions/dbexception.h \
        models/client.h \
        parameters.h

FORMS    += mainwindow.ui \
        dialogaddclient.ui

RESOURCES += \
        Ressources.qrc
