#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogs/userdatadialog.h"
#include "database/customerdatabase.h"
#include "database/projectdatabase.h"
#include "dialogs/dialogaddcustomer.h"
#include "widgets/customercontextualmenu.h"
#include "models/search.h"
#include "widgets/popup.h"
#include "dialogs/addprojectdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateTable();
    updateTree();
    ui->tblCustomers->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->trCustomers->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(
        ui->tblCustomers,
        SIGNAL(customContextMenuRequested(const QPoint &)),
        this,
        SLOT(openContextualMenuTable(const QPoint &)));
    connect(
        ui->trCustomers,
        SIGNAL(customContextMenuRequested(const QPoint &)),
        this,
        SLOT(openContextualMenuTree(const QPoint &)));

    updateUser();
    demo();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::demo() {
    /*ui->btnAddProject->setVisible(false);
=======
/*void MainWindow::demo() {
    ui->btnAddProject->setVisible(false);
>>>>>>> a937ef62efe4f960af33cadff1d77df583a75f87
    ui->actionNewBill->setVisible(false);
    ui->actionNewQuote->setVisible(false);
    ui->actResearch->setVisible(false);
    ui->btnNewProject->hide();
    ui->actionPrint->setVisible(false);*/
}

int MainWindow::getCurrentCustomerId() {
    QModelIndex idCell =
        ui->tblCustomers->model()->index(ui->tblCustomers->currentIndex().row(), 0);
    return ui->tblCustomers->model()->itemData(idCell).value(0).toInt();
}

void MainWindow::addCustomer()
{
    DialogAddCustomer win;
    if(win.exec()) {
        updateTable();
        updateTree();
    }
}


void MainWindow::editCustomer()
{
    if (ui->tblCustomers->selectionModel()->hasSelection()) {
        DialogAddCustomer winAddCustomer(getCurrentCustomerId());
        if(winAddCustomer.exec()) {
            updateTable();
            updateTree();
        }
    }
}

void MainWindow::removeCustomer()
{
    if (ui->tblCustomers->selectionModel()->hasSelection()) {
        if(QMessageBox::warning(
                    this,
                    "Suppression d'un client",
                    "Voulez vous supprimer le client sélectionné ? ",
                    "Supprimer",
                    "Annuler") == 0)
        {
            QModelIndex ls = ui->tblCustomers->selectionModel()->selectedRows().first();
            int pid = ui->tblCustomers->model()->data(ls,Qt::DisplayRole).toInt();
            Customer(pid).remove();
            updateTable();
            updateTree();
        }
    }
}

void MainWindow::updateUser()
{
    ui->wdgUserData->printUserData();
}

void MainWindow::openCustomer()
{
    int id = getCurrentCustomerId();
    ui->wdgCustomerData->printInformations(id);
}

void MainWindow::editUser()
{
    UserDataDialog userdialog;
    userdialog.exec();
    updateUser();
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
    s.setGroupFilter(ui->gpbxSearchFilter->isChecked());
    s.setSearchInCompanies(ui->chkSearchCompany->isChecked());
    s.setSearchInReferentLastname(ui->chkReferentName->isChecked());
    s.setText(text);
    updateTable(s.getFilter());
    updateTree(s.getFilter());
}

void MainWindow::openContextualMenuTable(const QPoint point)
{
    QMenu* menu = new CustomerContextualMenu(this);

    emit changeCustomerTable();
    QPoint buffPoint = point;
    buffPoint.setX(point.x()+35);
    buffPoint.setY(point.y()+35);
    menu->exec(ui->tblCustomers->mapToGlobal(buffPoint));
}
void MainWindow::openContextualMenuTree(const QPoint point)
{
    QMenu* menu = new CustomerContextualMenu(this);

    emit changeCustomerTree();
    QPoint buffPoint = point;
    buffPoint.setX(point.x()+35);
    buffPoint.setY(point.y()+35);
    menu->exec(ui->trCustomers->mapToGlobal(buffPoint));

}
void MainWindow::updateTable(QString filter)
{
    ui->tblCustomers->setModel(
                CustomerDatabase::instance()->getCustomersTable(filter));
    ui->tblCustomers->hideColumn(0);
    ui->tblCustomers->setColumnWidth(0, 100);
    ui->tblCustomers->setColumnWidth(1, 200);
    ui->tblCustomers->setColumnWidth(2, 100);
    ui->tblCustomers->setColumnWidth(3, 150);
    ui->tblCustomers->setColumnWidth(4, 150);
    ui->tblCustomers->setColumnWidth(5, 250);
}

void MainWindow::updateTableProjects(const int pId)
{
    ui->tblProjects->setModel(
                ProjectDatabase::instance()->getProjectsTable(pId));
    ui->tblProjects->hideColumn(0);
}

void MainWindow::updateTree(QString filter)
{
    ui->trCustomers->setModel(
                CustomerDatabase::instance()->getCustomersTree(filter));
    ui->trCustomers->header()->close();
}

void MainWindow::newProject()
{
    AddProjectDialog w;
    if(w.exec()) {

    }
}

void MainWindow::aboutQt()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::aboutFact()
{
    QMessageBox::about(
                this,
                "About Fact",
                "Fact est une équipe de Développement créée dans le cadre de "
                "projets pour l'Université Toulouse III - Paul Sabatier. <br />"
                "Cette équipe est composée de : "
                  "<ul>"
                       "<li>Florent Berbie</li>"
                       "<li>Manantsoa Andriamihary Razanajatovo</li>"
                       "<li>Cédric Rohaut</li>"
                       "<li>Antoine de Roquemaurel</li>"
                  "</ul>"
                "<br/><br/>"
                "Plus d'informations sur <a href=\"http://fact-team.github.io/\">http://fact-team.github.io/</a>");
}

void MainWindow::aboutFactDev()
{
    QMessageBox::about(
                this,
                "About FactDev",
                "<p>FactDev est un logiciel de Facture et Devis développé par "
                "l'équipe FACT dans le cadre de l'UE Projet pour l'université "
                "Toulouse III - Paul Sabatier.<br/></p>"
                "<p>"
               // "Ce logiciel est libre et sous license *****. "
                "<br/>Le code source est disponible sur Github : <br/><a href=\"https://github.com/FACT-Team/FactDev\">https://github.com/FACT-Team/FactDev</a>");
}

void MainWindow::aboutIcons()
{
     QMessageBox::about(
                 this,
                 "About Icons",
                 "Le pack d'icons à été développé par Florent Berbie pour "
                 "l'usage du logiciel FactDev");
}

void MainWindow::changeCustomerTree(QModelIndex index)
{
    ui->tblCustomers->selectRow(index.row()-1);     // Séléction de la ligne correspondante au client sélectionné
    emit openCustomer();
}

void MainWindow::changeCustomerTree()
{
    QModelIndex index =
            ui->trCustomers->model()->index(ui->trCustomers->currentIndex().row(), 0);
    emit changeCustomerTree(index);
}

void MainWindow::changeCustomerTable(QModelIndex index)
{
    // Gérer le rafraichissement des vues lors d'un changement d'état dans la séléction des clients
    // ui->trCustomers->set(index.row()+1);
    emit openCustomer();
}

void MainWindow::changeCustomerTable()
{
    QModelIndex index =
            ui->tblCustomers->model()->index(ui->tblCustomers->currentIndex().row(), 0);
    emit changeCustomerTable(index);
}

void MainWindow::changeProjectsTable()
{
    int id = getCurrentCustomerId();
    updateTableProjects(id);
    ui->tblProjects->hideColumn(0);
    ui->tblProjects->setColumnWidth(0, 100);
    ui->tblProjects->setColumnWidth(1, 150);
    ui->tblProjects->setColumnWidth(2, 200);
    ui->tblProjects->setColumnWidth(3, 125);
    ui->tblProjects->setColumnWidth(4, 125);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::backToCustomersTable()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::projectsCustomersTableTree()
{

    QModelIndex index = ui->trCustomers->selectionModel()->currentIndex();

    qDebug() << index.data(Qt::DisplayRole).toString();

    if (index.data(Qt::DisplayRole).toString() == "Tous les clients")
        ui->stackedWidget->setCurrentIndex(0);
    else if(index.model()->hasChildren()) { //si client
        ui->stackedWidget->setCurrentIndex(1);
        changeProjectsTable();
    }

    //TO DO: traiter lorqu'on clique sur un projet
}
