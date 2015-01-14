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
        database/userdatabase.cpp \
        dialogs/dialogaddcustomer.cpp \
        models/customer.cpp \
    models/project.cpp \
    models/billing.cpp \
    models/contributory.cpp \
    models/user.cpp \
    dialogs/userdatadialog.cpp \
    widgets/customercontextualmenu.cpp \
    models/search.cpp
    dialogs/addprojectdialog.cpp

HEADERS  += mainwindow.h \
        log.h\
        # Database files
        database/database.h \
        #Exceptions
        exceptions/dbexception.h \
        parameters.h \
        database/customerdatabase.h \
        database/userdatabase.h \
        models/customer.h \
        dialogs/dialogaddcustomer.h \
    models/project.h \
    models/idatabasemodel.h \
    models/billing.h \
    models/contributory.h \
    database/userdatabase.h \
    models/user.h \
    dialogs/userdatadialog.h \
    widgets/customercontextualmenu.h \
    models/search.h
    dialogs/addprojectdialog.h

FORMS    += mainwindow.ui \
        dialogs/dialogaddcustomer.ui \
    dialogs/userdatadialog.ui \
    dialogs/addprojectdialog.ui

RESOURCES += \
    icons.qrc

OTHER_FILES += \
        sql/removetable.sql \
        sql/createtables.sql\
        sql/tests.sql

