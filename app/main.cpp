#include "gui/mainwindow/mainwindow.h"
#include "gui/dialogs/userdatadialog.h"
#include <QApplication>
#include "database/database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gui::MainWindow w;
    QLocale::setDefault(QLocale(QLocale::French));

    w.show();
    return a.exec();
}
