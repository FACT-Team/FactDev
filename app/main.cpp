#include "gui/mainwindow/mainwindow.h"
#include "gui/dialogs/userdatadialog.h"
#include <QApplication>
#include <QSplashScreen>
#include "database/database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen* splash = new QSplashScreen(QPixmap(":/icons/FactDev"));
    splash->show();
    splash->showMessage("Chargement...\n Veuillez patienter svp", Qt::AlignHCenter|Qt::AlignBottom);
    Gui::MainWindow w;
    QLocale::setDefault(QLocale(QLocale::French));

    w.show();

    int ret = a.exec();
    splash->finish(&w);
    return ret;
}
