#include "mainwindow.h"
#include "gui/dialogs/userdatadialog.h"
#include <QApplication>
#include "database/database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gui::MainWindow w;

    w.show();
    return a.exec();
}
