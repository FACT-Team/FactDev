#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database/customerdatabase.h"
#include "dialogs/dialogaddcustomer.h"
#include "widgets/customercontextualmenu.h"
#include "models/search.h"
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
        updateTable();
        updateTree();
    } else {

    }

}

void MainWindow::editCustomer()
{
    // TODO Implement me
    qDebug() << "MainWindow::editCustomer" << "TODO Implement me";
}

void MainWindow::removeCustomer()
{
    // TODO Implement me
    qDebug() << "MainWindow::removeCustomer" << "TODO Implement me";
}

void MainWindow::openCustomer()
{
    // TODO Implement me
    qDebug() << "MainWindow::openCustomer" << "TODO Implement me";
}
void MainWindow::search() {
    emit search(ui->leSearch->text());
}

void MainWindow::search(QString text)
{
    Search s;
    s.setGroupFilter(ui->gpbxSearchFilter->isChecked());
    s.setSearchInCompanies(ui->chkSearchCompany->isChecked());
    s.setSearchInReferentLastname(ui->chkReferentName->isChecked());
    s.setText(text);
    qDebug() << s.getFilter();
    updateTable(s.getFilter());
    updateTree(s.getFilter());
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
void MainWindow::updateTable(QString filter)
{
    ui->tblCustomers->setModel(CustomerDatabase::instance()->getCustomersTable(filter));
    ui->tblCustomers->hideColumn(0);
    ui->tblCustomers->setColumnWidth(0, 100);
    ui->tblCustomers->setColumnWidth(1, 100);
    ui->tblCustomers->setColumnWidth(2, 100);
    ui->tblCustomers->setColumnWidth(3, 150);
    ui->tblCustomers->setColumnWidth(4, 200);
}

void MainWindow::updateTree(QString filter)
{
    ui->trCustomers->setModel(CustomerDatabase::instance()->getCustomersTree(filter));
}

