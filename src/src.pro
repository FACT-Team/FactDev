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
QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11


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
    models/search.cpp \
    widgets/popup.cpp \
    dialogs/addprojectdialog.cpp \
    widgets/ratewidget.cpp \
    database/projectdatabase.cpp \
    dialogs/addcontributorydialog.cpp \
    widgets/comboboxmodelwidget.cpp\
    utils.cpp \
    widgets/searchwidget.cpp \
    widgets/customerdatawidget.cpp \
    widgets/projectswidget.cpp \
    dialogs/addquotedialog.cpp \
    widgets/checkfields/checkqlineedit.cpp \
    widgets/checkfields/checkemail.cpp \
    widgets/checkfields/checkphone.cpp \
    widgets/checkfields/checkpostalcode.cpp \
    widgets/checkfields/checkcity.cpp \
    widgets/checkfields/checkcountry.cpp \
    widgets/checkfields/checkname.cpp \
    widgets/checkfields/checksiretnumber.cpp \
    widgets/checkfields/checkuntilfield.cpp \
    widgets/checkfields/checkvalidfield.cpp \
    widgets/checkfields/checkfieldsletters.cpp \
    widgets/contributorieswidget.cpp \
    widgets/widgetsmodels/contributoriestablemodel.cpp \
    widgets/delegates/projectcombodelegate.cpp \
    database/billingdatabase.cpp

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
    models/search.h \
    widgets/popup.h \
    dialogs/addprojectdialog.h \
    widgets/ratewidget.h \
    database/projectdatabase.h \
    dialogs/addcontributorydialog.h \
    widgets/comboboxmodelwidget.h \
    utils.h \
    widgets/searchwidget.h \
    widgets/customerdatawidget.h \
    widgets/projectswidget.h \
    dialogs/addquotedialog.h \
    widgets/checkfields/ICheckField.h \
    widgets/checkfields/checkqlineedit.h \
    widgets/checkfields/checkemail.h \
    widgets/checkfields/checkphone.h \
    widgets/checkfields/checkpostalcode.h \
    widgets/checkfields/checkcity.h \
    widgets/checkfields/checkcountry.h \
    widgets/checkfields/checkname.h \
    widgets/checkfields/checksiretnumber.h \
    widgets/checkfields/checkuntilfield.h \
    widgets/checkfields/checkvalidfield.h \
    widgets/checkfields/checkfieldsletters.h \
    widgets/contributorieswidget.h \
    widgets/widgetsmodels/contributoriestablemodel.h \
    widgets/delegates/projectcombodelegate.h \
    database/billingdatabase.h

FORMS    += mainwindow.ui \
        dialogs/dialogaddcustomer.ui \
    dialogs/userdatadialog.ui \
    dialogs/addprojectdialog.ui \
    widgets/ratewidget.ui \
    dialogs/addcontributorydialog.ui \
    widgets/comboboxmodelwidget.ui \
    widgets/searchwidget.ui \
    widgets/customerdatawidget.ui \
    widgets/projectswidget.ui \
    dialogs/addquotedialog.ui \
    widgets/contributorieswidget.ui

RESOURCES += \
    icons.qrc

OTHER_FILES += \
        sql/removetable.sql \
        sql/createtables.sql\
        sql/tests/customers.sql \
    sql/tests/user.sql \
    sql/tests/billings.sql \
    sql/tests/billingsprojects.sql \
    sql/tests/contributories.sql \
    sql/tests/projects.sql

