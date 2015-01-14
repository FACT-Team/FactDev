#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database/customerdatabase.h"
#include "dialogs/dialogaddcustomer.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateTable();
    updateTree();
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
        updateTable();
        updateTree();
    } else {

    }

}

void MainWindow::deleteCustomer()
{
    if (ui->tblCustomers->selectionModel()->hasSelection()) {
        qDebug() << "Delete";
        QModelIndex ls = ui->tblCustomers->selectionModel()->selectedRows().first();
        int pid = ui->tblCustomers->model()->data(ls,Qt::DisplayRole).toInt();
        CustomerDatabase::instance()->removeCustomer(pid);
        updateTable();
        updateTree();
    }


}

void MainWindow::updateTable()
{
    ui->tblCustomers->setModel(CustomerDatabase::instance()->getCustomersTable());
    ui->tblCustomers->hideColumn(0);
    ui->tblCustomers->setColumnWidth(0, 100);
    ui->tblCustomers->setColumnWidth(1, 100);
    ui->tblCustomers->setColumnWidth(2, 150);
    ui->tblCustomers->setColumnWidth(3, 150);
    ui->tblCustomers->setColumnWidth(4, 100);
    ui->tblCustomers->setColumnWidth(5, 200);
}

void MainWindow::updateTree()
{
    ui->trCustomers->setModel(CustomerDatabase::instance()->getCustomersTree());
}

