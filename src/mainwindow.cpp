#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database/customerdatabase.h"
#include "dialogs/dialogaddcustomer.h"
#include "widgets/customercontextualmenu.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateTable();
    updateTree();
    ui->tblCustomers->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->trCustomers->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tblCustomers, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(openContextualMenuTable(const QPoint &)));
    connect(ui->trCustomers, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(openContextualMenuTree(const QPoint &)));
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

void MainWindow::openContextualMenuTable(const QPoint point)
{
    QMenu* menu = new CustomerContextualMenu(this);

    QPoint buffPoint = point;
    buffPoint.setX(point.x()+35);
    buffPoint.setY(point.y()+35);
    menu->exec(ui->tblCustomers->mapToGlobal(buffPoint));
}
void MainWindow::openContextualMenuTree(const QPoint point)
{
    QMenu* menu = new CustomerContextualMenu(this);

    QPoint buffPoint = point;
    buffPoint.setX(point.x()+35);
    buffPoint.setY(point.y()+35);
    menu->exec(ui->trCustomers->mapToGlobal(buffPoint));
}
void MainWindow::updateTable()
{
    ui->tblCustomers->setModel(CustomerDatabase::instance()->getCustomersTable());
    ui->tblCustomers->hideColumn(0);
    ui->tblCustomers->setColumnWidth(0, 100);
    ui->tblCustomers->setColumnWidth(1, 100);
    ui->tblCustomers->setColumnWidth(2, 100);
    ui->tblCustomers->setColumnWidth(3, 150);
    ui->tblCustomers->setColumnWidth(4, 200);
}

void MainWindow::updateTree()
{
    ui->trCustomers->setModel(CustomerDatabase::instance()->getCustomersTree());
}

