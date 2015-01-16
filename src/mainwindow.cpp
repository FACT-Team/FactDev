#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogs/userdatadialog.h"
#include "database/customerdatabase.h"
#include "dialogs/dialogaddcustomer.h"
#include "widgets/customercontextualmenu.h"
#include "models/search.h"
#include "widgets/popup.h"
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

void MainWindow::addProject()
{

}

int MainWindow::getCurrentCustomerId() {
    QModelIndex idCell = ui->tblCustomers->model()->index(ui->tblCustomers->currentIndex().row(), 0);

    return ui->tblCustomers->model()->itemData(idCell).value(0).toInt();
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
    Popup::toImplement("MainWindow::editCustomer", this);
}

void MainWindow::removeCustomer()
{
    if (ui->tblCustomers->selectionModel()->hasSelection()) {
        if(QMessageBox::warning(this, "Suppression d'un client", "Voulez vous supprimer le client sélectionné ? ", "Supprimer", "Annuler") == 0) {

            qDebug() << "Delete";
            QModelIndex ls = ui->tblCustomers->selectionModel()->selectedRows().first();
            int pid = ui->tblCustomers->model()->data(ls,Qt::DisplayRole).toInt();
            CustomerDatabase::instance()->removeCustomer(pid);
            updateTable();
            updateTree();
        }
    }
}

void MainWindow::openCustomer()
{
    // TODO Implement me
    Popup::toImplement("MainWindow::openCustomer", this);
}

void MainWindow::editUser()
{
    UserDataDialog userdialog;

    if(userdialog.exec()) {        // Ouverture de la fenêtre pour ajouter/modifier un client

    } else {

    }
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
    updateTable(s.getFilter());
    updateTree(s.getFilter());

    QString styleSearchBackground =
            "background: url(:/icons/searchMini);"
            "background-position: right;"
            "background-repeat: no-repeat;     "
            "border-radius: 0px;"
            "height: 23px;"
            "border: 1px solid #bbb;";
    QString styleSearchNoBackground =
            "border-radius: 0px;"
            "height: 23px;"
            "border: 1px solid #bbb;";

    if(ui->leSearch->text() != "") {
        ui->leSearch->setStyleSheet(styleSearchNoBackground);
    } else {
        ui->leSearch->setStyleSheet(styleSearchBackground);
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
void MainWindow::updateTable(QString filter)
{
    ui->tblCustomers->setModel(CustomerDatabase::instance()->getCustomersTable(filter));
    ui->tblCustomers->hideColumn(0);
    ui->tblCustomers->setColumnWidth(0, 100);
    ui->tblCustomers->setColumnWidth(1, 100);
    ui->tblCustomers->setColumnWidth(2, 150);
    ui->tblCustomers->setColumnWidth(3, 150);
    ui->tblCustomers->setColumnWidth(4, 100);
    ui->tblCustomers->setColumnWidth(5, 200);
}

void MainWindow::updateTree(QString filter)
{
    ui->trCustomers->setModel(CustomerDatabase::instance()->getCustomersTree(filter));
}

void MainWindow::updateUserData()
{

    User user;
    ui->lbName->setText(user.getFirstname()+" "+user.getLastname());
    ui->lbCompany->setText(user.getCompany());
    ui->lbAddress->setText(user.getAddress());
    ui->lbPostalCodeCity->setText(user.getPostalCode()+", "+user.getCity());
    ui->lbEmail->setText(user.getEmail());
    ui->lbPhone->setText(user.getPhone());

    user.commit();
}

