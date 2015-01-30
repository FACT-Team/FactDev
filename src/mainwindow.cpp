#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogs/userdatadialog.h"
#include "database/customerdatabase.h"
#include "database/projectdatabase.h"
#include "database/billingdatabase.h"
#include "dialogs/dialogaddcustomer.h"
#include "widgets/customercontextualmenu.h"
#include "models/search.h"
#include "widgets/popup.h"
#include "dialogs/addprojectdialog.h"
#include "dialogs/addquotedialog.h"
#include "log.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    updateTableCustomers();
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

}

int MainWindow::getCurrentTableId(QTableView *tbl) {
    QModelIndex idCell = tbl->model()->index(tbl->currentIndex().row(), 0);
    return tbl->model()->itemData(idCell).value(0).toInt();
}

int MainWindow::getCurrentCustomerId() {
   return getCurrentTableId(ui->tblCustomers);
}

int MainWindow::getCurrentProjectId() {
    return getCurrentTableId(ui->tblProjects);
}


QString MainWindow::getCurrentCustomerName()
{
    QModelIndex index =
            ui->tblCustomers->model()->index(ui->tblCustomers->currentIndex().row(),1);
    return index.model()->itemData(index).value(0).toString();
}

QString MainWindow::getCurrentProjectName()
{
    QModelIndex index =
            ui->tblProjects->model()->index(ui->tblProjects->currentIndex().row(),1);
    return index.model()->itemData(index).value(0).toString();
}

bool MainWindow::isCustomer()
{
    QModelIndex index = ui->trCustomers->selectionModel()->currentIndex();
    return index.model()->hasChildren(index);
}

bool MainWindow::isTreeRoot() {
    return ui->trCustomers->currentIndex().data() == "Tous les clients";
}
bool MainWindow::isProjectItemTree() {
    return false;
}
bool MainWindow::isCustomerItemTree() {
    return !isTreeRoot() && !ui->trCustomers->currentIndex().parent().isValid();
}
bool MainWindow::isQuoteItemTree() {
    return false;
}

void MainWindow::addCustomer()
{
    DialogAddCustomer win;
    if(win.exec()) {
        updateTableCustomers();
        updateTree();
    }
}


void MainWindow::editCustomer() {
    if (ui->tblCustomers->selectionModel()->hasSelection()) {
        DialogAddCustomer winAddCustomer(getCurrentCustomerId());
        if(winAddCustomer.exec()) {
            updateTableCustomers();
            updateTree();
        }
    }
}

void MainWindow::removeCustomer() {
    removeItem(ui->tblCustomers, ItemType(ItemType::CUSTOMER, "client"));
}

void MainWindow::updateUser()
{
    ui->wdgUserData->printUserData();
}

void MainWindow::removeItem(QTableView *tbl, ItemType itemType)
{
    if (tbl->selectionModel()->hasSelection()) {
        if(QMessageBox::warning(
                    this,
                    "Suppression d'"+ QString((itemType.getType() == ItemType::BILLING ? "une " : "un ")) + itemType.getName(),
                    "Voulez vous supprimer " +
                    (itemType.getType() == ItemType::BILLING ?
                            "la " +itemType.getName()+" séléctionnée" :
                            "le "+itemType.getName()+" sélectionné") + " ?",
                    "Supprimer",
                    "Annuler") == 0)
        {
            QModelIndex ls = tbl->selectionModel()->selectedRows().first();
            int pid = tbl->model()->data(ls,Qt::DisplayRole).toInt();
            itemType.getModel(pid)->remove();
            updateTableCustomers();
            updateTree();
            updateTableProjects();
        }
    }
}



void MainWindow::updateTableBillings(const int idProject)
{
    ui->tblQuotes->setModel(
                BillingDatabase::instance()->getBillingsTable(idProject));
    ui->lblQuotes->setText("<b>Devis du projet: "+getCurrentProjectName()+"</b>");
    ui->tblQuotes->hideColumn(0);
    ui->tblQuotes->hideColumn(3);
    ui->tblQuotes->setColumnWidth(1, 200);
    ui->tblQuotes->setColumnWidth(2, 100);
    ui->tblQuotes->setColumnWidth(4, 150);
}


void MainWindow::addQuote()
{
    if (ui->tblCustomers->selectionModel()->hasSelection()) {
        AddQuoteDialog winAddQuote(getCurrentCustomerId());
        if(winAddQuote.exec()) {

        }
    } else {
        Popup *p = new Popup();
        p->toImplement("\nVeuillez sélectionner un client", this);
    }
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
    updateTableCustomers(s.getFilter());
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
    updateTableCustomers(s.getFilter());
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

    emit changeTree();
    QPoint buffPoint = point;
    buffPoint.setX(point.x()+35);
    buffPoint.setY(point.y()+35);
    menu->exec(ui->trCustomers->mapToGlobal(buffPoint));

}

void MainWindow::updateTableCustomers(QString filter)
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
    static int lastId = pId;
    if(pId != 0) {
        lastId = pId;
    }
    qDebug() << lastId;
    ui->tblProjects->setModel(ProjectDatabase::instance()->getProjectsTable(lastId));
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
    QModelIndex index = ui->tblCustomers->currentIndex();
    AddProjectDialog *w = new AddProjectDialog();
    if (ui->tblCustomers->selectionModel()->hasSelection()) {
        w = new AddProjectDialog(index.row(), 0, 0);
    }

    if(w->exec()) {

    }
    updateTree("");
}


void MainWindow::removeProject() {
    removeItem(ui->tblProjects, ItemType(ItemType::PROJECT, "projet"));
}

void MainWindow::editProject() {

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

void MainWindow::changeTree()
{
    QModelIndex index = ui->trCustomers->currentIndex();
    int idRow = ui->trCustomers->currentIndex().row();
    int id = getCurrentCustomerId();
    //QModelIndex a = ui->trCustomers->model()->index(1,0, QModelIndex);
    //Customer custom(index.data());


    qDebug() << "Row : " << idRow << "\tCustomer id : " << id << " " << index.data().toString() << " " << isTreeRoot();

    //qDebug() << "";
    if (isTreeRoot()) {
        qDebug() << "Clear";
        ui->tblCustomers->clearSelection();
        ui->wdgCustomerData->hide();
    }

    if (isCustomerItemTree()) {
        qDebug() << "Customer" << id << " " << idRow;
        ui->tblCustomers->selectRow(idRow-1);
        ui->wdgCustomerData->printInformations(id);
    }
}

void MainWindow::changeCustomerTable()
{
    //QModelIndex index = ui->tblCustomers->model()->index(ui->tblCustomers->currentIndex().row(), 0);
    int id = getCurrentCustomerId();
    ui->wdgCustomerData->printInformations(id);
}

void MainWindow::changeProjectsTable()
{
    int id = getCurrentCustomerId();
    updateTableProjects(id);
    ui->lblProjects->setText("<b>Projet(s) de: " + getCurrentCustomerName()+"</b>");
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

void MainWindow::backToProjectsTable()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::projectsCustomersTableTree()
{

    /*QModelIndex index = ui->trCustomers->selectionModel()->currentIndex();

    if (index.data(Qt::DisplayRole).toString() == "Tous les clients")
        ui->stackedWidget->setCurrentIndex(0);
    else if(isCustomer()) { //si client
        ui->stackedWidget->setCurrentIndex(1);
        changeProjectsTable();
        ui->trCustomers->collapseAll();
        ui->trCustomers->expand(index);
    }
    else { //si projet
        ui->tblProjects->selectRow(index.row());
        ui->stackedWidget->setCurrentIndex(2);
        updateTableBillings(getCurrentProjectId());
    */
}

void MainWindow::quotesProject()
{
    ui->stackedWidget->setCurrentIndex(2);
    updateTableBillings(getCurrentProjectId());
}
