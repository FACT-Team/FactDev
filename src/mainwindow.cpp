#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database/database.h"
#include "dialogs/dialogaddcustomer.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Database::instance();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCustomer()
{
    DialogAddCustomer win;
    if(win.exec()) {        // Ouverture de la fenêtre pour ajouter/modifier un client
        qDebug() << "accept";
    } else {

    }

}

