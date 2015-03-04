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

linux-g++ {
    QMAKE_CXXFLAGS += -std=c++0x -fprofile-arcs -ftest-coverage
    QMAKE_LDFLAGS += -fprofile-arcs -ftest-coverage
    LIBS =  -lgcov
}
CONFIG += c++11


SOURCES += gui/mainwindow/mainwindow.cpp \
        utils/log.cpp\
        # Database files
        database/database.cpp \
        # Exceptions
        exceptions/dbexception.cpp \
        parameters.cpp \
        database/customerdatabase.cpp \
        database/userdatabase.cpp \
        gui/dialogs/dialogaddcustomer.cpp \
        models/customer.cpp \
    models/project.cpp \
    models/billing.cpp \
    models/contributory.cpp \
    models/user.cpp \
    gui/dialogs/userdatadialog.cpp \
    gui/widgets/customercontextualmenu.cpp \
    models/search.cpp \
    gui/widgets/popup.cpp \
    gui/dialogs/addprojectdialog.cpp \
    gui/widgets/ratewidget.cpp \
    database/projectdatabase.cpp \
    gui/widgets/comboboxmodelwidget.cpp\
    utils/string.cpp \
    gui/widgets/searchwidget.cpp \
    gui/widgets/customerdatawidget.cpp \
    gui/widgets/projectswidget.cpp \
    gui/dialogs/addquotedialog.cpp \
    gui/widgets/checkfields/checkqlineedit.cpp \
    gui/widgets/checkfields/checkemail.cpp \
    gui/widgets/checkfields/checkphone.cpp \
    gui/widgets/checkfields/checkpostalcode.cpp \
    gui/widgets/checkfields/checkcity.cpp \
    gui/widgets/checkfields/checkcountry.cpp \
    gui/widgets/checkfields/checkname.cpp \
    gui/widgets/checkfields/checksiretnumber.cpp \
    gui/widgets/checkfields/checkuntilfield.cpp \
    gui/widgets/checkfields/checkvalidfield.cpp \
    gui/widgets/checkfields/checkfieldsletters.cpp \
    gui/widgets/contributorieswidget.cpp \
    gui/widgets/widgetsmodels/contributoriestablemodel.cpp \
    gui/widgets/delegates/projectcombodelegate.cpp \
    database/billingdatabase.cpp \
    database/contributorydatabase.cpp \
    utils/itemtype.cpp \
    gui/dialogs/messagebox.cpp \
    libs/qt-mustache/src/mustache.cpp \
    generator.cpp \
    gui/widgets/widgetsmodels/customerstablemodel.cpp \
    gui/widgets/widgetsmodels/projectstablemodel.cpp \
    gui/widgets/widgetsmodels/billingstablemodel.cpp \
    models/contributorieslist.cpp \
    gui/widgets/widgetsmodels/projectcontributoriestablemodel.cpp \
    gui/widgets/delegates/doublespinboxdelegate.cpp \
    models/rate.cpp \
    gui/widgets/delegates/unitcombodelegate.cpp \
    gui/widgets/delegates/comboboxdelegate.cpp \
    database/ratedatabase.cpp \
    exceptions/fileexception.cpp \
    utils/hierarchicalsystem.cpp \
    gui/mainwindow/customers.cpp \
    utils/pointers.cpp \
    utils/directories.cpp \
    gui/docks/searchdock.cpp

HEADERS  += gui/mainwindow/mainwindow.h \
        utils/log.h\
        # Database files
        database/database.h \
        #Exceptions
        exceptions/dbexception.h \
        parameters.h \
        database/customerdatabase.h \
        database/userdatabase.h \
        models/customer.h \
        gui/dialogs/dialogaddcustomer.h \
        models/project.h \
        models/billing.h \
        models/contributory.h \
        database/userdatabase.h \
        models/user.h \
        gui/widgets/customercontextualmenu.h \
        models/search.h \
        gui/widgets/popup.h \
        gui/widgets/ratewidget.h \
        database/projectdatabase.h \
        utils/string.h \
        gui/widgets/projectswidget.h \
        gui/widgets/checkfields/checkqlineedit.h \
        gui/widgets/checkfields/checkemail.h \
        gui/widgets/checkfields/checkphone.h \
        gui/widgets/checkfields/checkpostalcode.h \
        gui/widgets/checkfields/checkcity.h \
        gui/widgets/checkfields/checkcountry.h \
        gui/widgets/checkfields/checkname.h \
        gui/widgets/checkfields/checksiretnumber.h \
        gui/widgets/checkfields/checkuntilfield.h \
        gui/widgets/checkfields/checkvalidfield.h \
        gui/widgets/checkfields/checkfieldsletters.h \
        gui/widgets/widgetsmodels/contributoriestablemodel.h \
        database/billingdatabase.h \
        database/contributorydatabase.h \
        utils/itemtype.h \
        gui/widgets/checkfields/icheckfield.h \
        libs/qt-mustache/src/mustache.h \
        generator.h \
        models/imodel.h \
        gui/widgets/widgetsmodels/customerstablemodel.h \
        gui/widgets/widgetsmodels/projectstablemodel.h \
        gui/widgets/widgetsmodels/billingstablemodel.h \
        models/contributorieslist.h \
        gui/widgets/widgetsmodels/projectcontributoriestablemodel.h \
        gui/widgets/delegates/doublespinboxdelegate.h \
        models/rate.h \
        gui/widgets/delegates/unitcombodelegate.h \
        gui/widgets/delegates/comboboxdelegate.h \
        database/ratedatabase.h\
    models/project.h \
    models/billing.h \
    models/contributory.h \
    database/userdatabase.h \
    models/user.h \
    gui/dialogs/userdatadialog.h \
    gui/widgets/customercontextualmenu.h \
    models/search.h \
    gui/widgets/popup.h \
    gui/dialogs/addprojectdialog.h \
    database/projectdatabase.h \
    gui/dialogs/addcontributorydialog.h \
    gui/widgets/comboboxmodelwidget.h \
    utils/string.h \
    gui/widgets/searchwidget.h \
    gui/widgets/customerdatawidget.h \
    gui/dialogs/addquotedialog.h \
    gui/widgets/checkfields/checkemail.h \
    gui/widgets/checkfields/checkphone.h \
    gui/widgets/checkfields/checkpostalcode.h \
    gui/widgets/checkfields/checkcity.h \
    gui/widgets/checkfields/checkcountry.h \
    gui/widgets/checkfields/checkname.h \
    gui/widgets/checkfields/checksiretnumber.h \
    gui/widgets/checkfields/checkuntilfield.h \
    gui/widgets/checkfields/checkvalidfield.h \
    gui/widgets/checkfields/checkfieldsletters.h \
    gui/widgets/contributorieswidget.h \
    gui/widgets/widgetsmodels/contributoriestablemodel.h \
    gui/widgets/delegates/projectcombodelegate.h \
    database/billingdatabase.h \
    database/contributorydatabase.h \
    utils/itemtype.h \
    gui/dialogs/messagebox.h \
    gui/widgets/checkfields/icheckfield.h \
    libs/qt-mustache/src/mustache.h \
    generator.h \
    models/imodel.h \
    gui/widgets/widgetsmodels/customerstablemodel.h \
    gui/widgets/widgetsmodels/projectstablemodel.h \
    gui/widgets/widgetsmodels/billingstablemodel.h \
    exceptions/fileexception.h \
    utils/hierarchicalsystem.h \
    gui/mainwindow/docks/searchdock.h \
    gui/mainwindow/customers.h \
    utils/pointers.h \
    utils/directories.h \
    gui/docks/searchdock.h


FORMS    += gui/mainwindow/mainwindow.ui \
        gui/dialogs/dialogaddcustomer.ui \
    gui/dialogs/userdatadialog.ui \
    gui/dialogs/addprojectdialog.ui \
    gui/widgets/ratewidget.ui \
    gui/widgets/comboboxmodelwidget.ui \
    gui/widgets/searchwidget.ui \
    gui/widgets/customerdatawidget.ui \
    gui/widgets/projectswidget.ui \
    gui/dialogs/addquotedialog.ui \
    gui/widgets/contributorieswidget.ui \
    gui/dialogs/messagebox.ui \
    gui/docks/searchdock.ui

RESOURCES += \
    icons.qrc \
    utilsfiles.qrc

OTHER_FILES += \
        sql/removetable.sql \
        sql/createtables.sql\
        sql/tests/customers.sql \
    sql/tests/user.sql \
    sql/tests/billings.sql \
    sql/tests/billingsprojects.sql \
    sql/tests/contributories.sql \
    sql/tests/projects.sql \
    main.dox \
    billing.tpl\

DISTFILES += \
    sql/tests/removeuselessdata.sql \
    sql/tests/billingrate.sql

