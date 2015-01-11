#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T13:44:51
#
#-------------------------------------------------
include(../defaults.pri)

QT       += core gui sql printsupport

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FactDev
TEMPLATE = lib


SOURCES += mainwindow.cpp \
        log.cpp\
        # Database files
        database/database.cpp \
        # Exceptions
        exceptions/dbexception.cpp \
        parameters.cpp \
        database/customerdatabase.cpp \
        dialogs/dialogaddcustomer.cpp \
        models/customer.cpp \
    models/project.cpp \
    models/billing.cpp \
    models/contributory.cpp \

HEADERS  += mainwindow.h \
        log.h\
        # Database files
        database/database.h \
        #Exceptions
        exceptions/dbexception.h \
        parameters.h \
        database/customerdatabase.h \
        models/customer.h \
        dialogs/dialogaddcustomer.h \
    models/project.h \
    models/idatabasemodel.h \
    models/billing.h \
    models/contributory.h \

FORMS    += mainwindow.ui \
        dialogs/dialogaddcustomer.ui

RESOURCES += \
        Ressources.qrc

OTHER_FILES += \
        sql/removetable.sql \
    sql/createtables.sql

