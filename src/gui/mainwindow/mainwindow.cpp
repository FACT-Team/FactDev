#include <QStandardPaths>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace Utils;

namespace Gui {
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setupUi();
    setupSignalsSlots();
}

void MainWindow::setupUi()
{
    ui->setupUi(this);
    _searchDock = new Docks::SearchDock();
    addDockWidget(Qt::LeftDockWidgetArea, _searchDock);
    addDockWidget(Qt::LeftDockWidgetArea, ui->dockCustomers);

    ui->stackedWidget->setCurrentIndex(0);
    updateTableCustomers();
    updateTree();
    updateUser();
    updateButtons();
    updateFolders();
}

void MainWindow::setupSignalsSlots()
{
    connect(
        ui->tblCustomers,
        SIGNAL(customContextMenuRequested(const QPoint &)),
        this,
        SLOT(openContextualMenuTable(const QPoint &)));
    connect(_searchDock, SIGNAL(textChanged(QString)), this, SLOT(search(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
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

int MainWindow::getCurrentQuoteId()
{
    return getCurrentTableId(ui->tblQuotes);
}

QString MainWindow::getCurrentCustomerName()
{
    QModelIndex index =
        ui->tblCustomers->model()->index(ui->tblCustomers->currentIndex().row(),1);
    return index.model()->itemData(index).value(0).toString();
}

QString MainWindow::getCurrentProjectName()
{
    QModelIndex index = ui->tblProjects->currentIndex();
    return index.data().toString();
}

void MainWindow::addCustomer()
{
    DialogAddCustomer addCustomerDialog;
    if (addCustomerDialog.exec()) { // accept
        ui->stackedWidget->setCurrentIndex(0);
        updateUI();
    }
}

void MainWindow::newProject()
{
    AddProjectDialog *addProjectDialog =
            ui->stackedWidget->currentIndex() == 1 ? new AddProjectDialog(0, ui->tblCustomers->currentIndex().row())
                                                   : new AddProjectDialog();

    if (addProjectDialog->exec()) {
        updateUI();
        ui->trCustomers->expand(ui->trCustomers->currentIndex());
    }
}

void MainWindow::addQuote() {
    addDoc(false);
}

void MainWindow::addBill()
{
    addDoc(true);
}

void MainWindow::addDoc(bool isBilling) {
    AddQuoteDialog addDocDialog(isBilling, getCurrentCustomerId());
    if (addDocDialog.exec()) {
        updateUI();
        changeCustomerTable();
        ui->trCustomers->expand(ui->trCustomers->currentIndex());
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::removeItem(QTableView *tbl, ItemType itemType)
{
    if (QMessageBox::warning(this,"Suppression d'"
                + QString((itemType.getType() == ItemType::BILLING ?
                           "une " : "un ")) + itemType.getName(),
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
        updateTree();
        switch(itemType.getType()) {
        case ItemType::CUSTOMER:
            updateTableCustomers();
            ui->trCustomers->setCurrentIndex(rootTree());
            break;
        case ItemType::PROJECT:
            updateTableProjects();
            changeCustomerTable();
            ui->trCustomers->expand(ui->trCustomers->currentIndex());
            break;
        case ItemType::BILLING:
            updateTableBillings(getCurrentProjectId());
            changeCustomerTable();
            ui->trCustomers->expand(ui->trCustomers->currentIndex());
            changeProjectsTable();
            ui->trCustomers->expand(ui->trCustomers->currentIndex());
            break;
        }
    }
    updateButtons();
}

void MainWindow::editCustomer() {
    DialogAddCustomer editCustomerDialog(getCurrentCustomerId());
    if (editCustomerDialog.exec()) {
        updateTableCustomers();
        updateTree();
        ui->trCustomers->setCurrentIndex(rootTree());
    }
}

void MainWindow::editProject() {
    int row = ui->tblProjects->currentIndex().row();
    AddProjectDialog editProjectDialog(row, getCurrentProjectId());
    if (editProjectDialog.exec()) {
        updateTableProjects(getCurrentCustomerId());
        updateTree();
        changeCustomerTable();
        ui->trCustomers->expand(ui->trCustomers->currentIndex());
    }
}

void MainWindow::editDoc()
{
    Billing b(getCurrentQuoteId());
    AddQuoteDialog editDocDialog(b.isBilling(), getCurrentCustomerId(),getCurrentQuoteId());

    if (editDocDialog.exec()) {
        updateTableBillings(getCurrentProjectId());
        updateTree();
        changeCustomerTable();
        ui->trCustomers->expand(ui->trCustomers->currentIndex());
        changeProjectsTable();
        ui->trCustomers->expand(ui->trCustomers->currentIndex());
    }
}

void MainWindow::removeCustomer() {
    removeItem(ui->tblCustomers, ItemType(ItemType::CUSTOMER, "client"));
}

void MainWindow::removeProject() {
    removeItem(ui->tblProjects, ItemType(ItemType::PROJECT, "projet"));
}

void MainWindow::removeDoc() {
    removeItem(ui->tblQuotes, ItemType(ItemType::BILLING, "document"));
}

void MainWindow::generateTex()
{
    QModelIndex ls = ui->tblQuotes->selectionModel()->selectedRows().first();
    int pid = ui->tblQuotes->model()->data(ls, Qt::DisplayRole).toInt();
    Billing(pid).generateTex();
}

void MainWindow::search(QString text)
{
    updateUI(text);
}

void MainWindow::editUser()
{
    UserDataDialog userdialog;
    if (userdialog.exec()) {
        updateUser();
    }
    updateUI();
}

void MainWindow::aboutQt()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::aboutFact()
{
    MessageBox::showAboutFact();
}

void MainWindow::aboutFactDev() {
    MessageBox::showAboutFactDev();
}

void MainWindow::aboutIcons() {
    MessageBox::showAboutIcons();
}

int MainWindow::treeLevel() {
    int ret = 0;

    QModelIndex currentIndex = ui->trCustomers->currentIndex();
    if (currentIndex.data() != "Tous les clients") {
        ret++;      // Level = 1, item != root
        while (currentIndex.parent().isValid()) {
            currentIndex = currentIndex.parent();
            ret++;
        }
    }
    return ret;
}

void MainWindow::changeTree()
{
    QModelIndex index = ui->trCustomers->currentIndex();
    int idRow = index.row();
    switch (treeLevel()) {
    case 0:         // Root "Tous les clients"
        ui->stackedWidget->setCurrentIndex(0);
        ui->tblCustomers->clearSelection();
        ui->wdgCustomerData->hide();
        ui->trCustomers->collapseAll();
        break;
    case 1:         // Customer
        ui->tblCustomers->selectRow(idRow-1);
        ui->wdgCustomerData->printInformations(getCurrentCustomerId());
        ui->trCustomers->collapseAll();
        ui->trCustomers->expand(index);
        customersTableToProjectsTable();
        ui->stackedWidget->setCurrentIndex(1);
        break;
    case 2:         // Project
        // Need to verify if the current customer is the father
        // Then update TableProjects
        ui->tblCustomers->selectRow(index.parent().row()-1);
        updateTableProjects(getCurrentCustomerId());
        ui->tblProjects->selectRow(idRow);
        updateTableBillings(getCurrentProjectId());
        //ui->trCustomers->collapseAll();
        ui->trCustomers->expand(index);
        ui->stackedWidget->setCurrentIndex(2);
        break;
    case 3:         // Bill/Quote
        // Need to verify if the current customer is the father
        // Need to verify if the current project is the father, also add the
        // quote in all fathers where it is referenced
        ui->tblCustomers->selectRow(index.parent().parent().row()-1);
        updateTableProjects(getCurrentCustomerId());
        ui->tblProjects->selectRow(index.parent().row());
        updateTableBillings(getCurrentProjectId());
        ui->tblQuotes->selectRow(idRow);
        ui->stackedWidget->setCurrentIndex(2);
        break;
    default:        // Other
        Log::instance(WARNING) << "MainWindow::changeTree – I don't know what I'm doing here… ";
    }
    updateButtons();
}

void MainWindow::changeCustomerTable()
{
    ui->wdgCustomerData->printInformations(getCurrentCustomerId());
    QModelIndex index(rootTree());

    for (int i = 0 ; i <= ui->tblCustomers->currentIndex().row() ; ++i) {
        index = ui->trCustomers->indexBelow(index);
    }
    ui->trCustomers->setCurrentIndex(index);
    updateButtons();
}

void MainWindow::changeProjectsTable()
{
    int row = ui->tblProjects->currentIndex().row();
    QModelIndex index(ui->trCustomers->currentIndex());
    if (treeLevel() == 2) {
        index = findParent();
    }

    for (int i = 0 ; i <= row ; ++i) {
        index = ui->trCustomers->indexBelow(index);
    }

    ui->trCustomers->setCurrentIndex(index);
    updateButtons();
}

void MainWindow::changeDocsTable()
{
    int row = ui->tblQuotes->currentIndex().row();
    QModelIndex index(ui->trCustomers->currentIndex());

    if (treeLevel() == 3) {
        index = findParent();
    }

    for (int i = 0 ; i <= row ; ++i) {
        index = ui->trCustomers->indexBelow(index);
    }

    ui->trCustomers->setCurrentIndex(index);
    updateButtons();
}

void MainWindow::customersTableToProjectsTable()
{
    updateTableProjects(getCurrentCustomerId());
    ui->lblProjects->setText(
                "<b>Projet(s) de: " + getCurrentCustomerName()+"</b>");
    ui->tblProjects->setColumnWidth(0, 100);
    ui->tblProjects->setColumnWidth(1, 150);
    ui->tblProjects->setColumnWidth(2, 200);
    ui->tblProjects->setColumnWidth(3, 122);
    ui->tblProjects->setColumnWidth(4, 122);
    ui->stackedWidget->setCurrentIndex(1);
    QModelIndex index(ui->trCustomers->currentIndex());
    ui->trCustomers->expand(index);
    updateButtons();
}

void MainWindow::projectsTableToDocsTable()
{
    ui->stackedWidget->setCurrentIndex(2);
    updateTableBillings(getCurrentProjectId());
    QModelIndex index(ui->trCustomers->currentIndex());
    ui->trCustomers->expand(index);
    updateButtons();
}

QModelIndex MainWindow::rootTree() {
    QModelIndex root = ui->trCustomers->indexAt(QPoint());
    while (ui->trCustomers->indexAbove(root).isValid())
        root = ui->trCustomers->indexAbove(root);

    return root;
}

QModelIndex MainWindow::findParent() {
    QModelIndex parent(ui->trCustomers->currentIndex());
    switch (treeLevel()) {
    case 2:
        while (parent.parent().isValid())
            parent = ui->trCustomers->indexAbove(parent);
        break;
    case 3:
        while (parent.parent().parent().isValid())
            parent = ui->trCustomers->indexAbove(parent);
        break;
    default:
        Log::instance(WARNING) << "MainWindow::findParent – I don't know what I'm doing here… ";
    }

    return parent;
}

void MainWindow::backToCustomersTable()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->trCustomers->collapseAll();
    changeCustomerTable();
    updateButtons();
}

void MainWindow::backToProjectsTable()
{
    ui->stackedWidget->setCurrentIndex(1);
    QModelIndex index(ui->trCustomers->currentIndex());
    if (treeLevel() != 2) {
        index = findParent();
    }
    ui->trCustomers->collapse(index);
    ui->trCustomers->setCurrentIndex(index);
}

void MainWindow::updateUI(QString filter)
{
    Utils::pointers::deleteIfNotNull(ui->tblCustomers->model());
    updateTableCustomers(filter, ui->tblCustomers->currentIndex().row());

    Utils::pointers::deleteIfNotNull(ui->tblProjects->model());
    updateTableProjects(getCurrentCustomerId(), ui->tblProjects->currentIndex().row());

    Utils::pointers::deleteIfNotNull(ui->tblQuotes->model());
    updateTableBillings(getCurrentProjectId(), ui->tblQuotes->currentIndex().row());

    Utils::pointers::deleteIfNotNull(ui->trCustomers->model());
    updateTree(filter);

    updateButtons();
    updateUser();
    updateFolders();
}

void MainWindow::openContextualMenuTable(const QPoint point) {
    QMenu* menu = new Gui::Widgets::CustomerContextualMenu(this);

    emit changeCustomerTable();
    QPoint buffPoint = point;
    buffPoint.setX(point.x()+35);
    buffPoint.setY(point.y()+35);
    menu->exec(ui->tblCustomers->mapToGlobal(buffPoint));
}

void MainWindow::openContextualMenuTree(const QPoint point)
{
    QMenu* menu = new Gui::Widgets::CustomerContextualMenu(this);

    emit changeTree();
    QPoint buffPoint = point;
    buffPoint.setX(point.x()+35);
    buffPoint.setY(point.y()+35);
    menu->exec(ui->trCustomers->mapToGlobal(buffPoint));
}


void MainWindow::updateTableCustomers(QString filter, const int row) {
    ui->tblCustomers->setModel(
        Databases::CustomerDatabase::instance()->getCustomersTable(filter));

    ui->tblCustomers->hideColumn(0);
    ui->tblCustomers->setColumnWidth(0, 100);
    ui->tblCustomers->setColumnWidth(1, 200);
    ui->tblCustomers->setColumnWidth(2, 100);
    ui->tblCustomers->setColumnWidth(3, 150);
    ui->tblCustomers->setColumnWidth(4, 150);
    ui->tblCustomers->setColumnWidth(5, 250);
    if (row > -1) {
        ui->tblCustomers->selectRow(row);
    } else {
        ui->tblCustomers->clearSelection();
    }
}

void MainWindow::updateTableProjects(const int pId, const int row)
{
    static int lastId = pId;
    if(pId != 0) {
        lastId = pId;
    }
    ui->tblProjects->setModel(
        Databases::ProjectDatabase::instance()->getProjectsTable(lastId));
    ui->tblProjects->hideColumn(0);

    if (row > -1) {
        ui->tblProjects->selectRow(row);
    } else {
        ui->tblProjects->clearSelection();
    }
}

void MainWindow::updateTableBillings(const int idProject, const int row)
{
    ui->tblQuotes->setModel(
        Databases::BillingDatabase::instance()->getBillingsTable(idProject));
    ui->lblQuotes->setText("<b>Devis du projet: "
                           + getCurrentProjectName()
                           + "</b>");
    ui->tblQuotes->hideColumn(0);
    ui->tblQuotes->hideColumn(3);
    ui->tblQuotes->setColumnWidth(1, 200);
    ui->tblQuotes->setColumnWidth(2, 100);
    ui->tblQuotes->setColumnWidth(4, 150);
    if (row > -1) {
        ui->tblQuotes->selectRow(row);
    } else {
        ui->tblQuotes->clearSelection();
    }
}

void MainWindow::updateTree(QString filter)
{
    ui->trCustomers->setModel(Databases::CustomerDatabase::instance()->getTree(filter));
}

void MainWindow::updateButtons()
{
    bool canModify = ui->stackedWidget->currentIndex() == 0
            && ui->tblCustomers->currentIndex().row() > -1
            && ui->tblCustomers->selectionModel()->hasSelection();
    bool canAdd =  (ui->stackedWidget->currentIndex() == 1
                    || ui->stackedWidget->currentIndex() == 2)
                    && ui->tblProjects->currentIndex().row() > -1
                    && ui->tblProjects->selectionModel()->hasSelection();


    bool billingIsSelected = ui->stackedWidget->currentIndex() == 2
            && ui->tblQuotes->currentIndex().row() > -1
            && ui->tblQuotes->selectionModel()->hasSelection();

    ui->btnEdit->setEnabled(canModify);
    ui->btnDelCustomer->setEnabled(canModify);

    if(!canModify) {
        ui->trCustomers->setCurrentIndex(rootTree());
    }
    ui->actionNewQuote->setEnabled(canAdd);
    ui->actionNewBill->setEnabled(canAdd);
    ui->wdgTblProjectsToolBar->updateBtn(canAdd);
    ui->btnRemoveDoc->setEnabled(billingIsSelected);
    ui->btnEditDoc->setEnabled(billingIsSelected);
    ui->btnLatex->setEnabled(billingIsSelected);

    if (billingIsSelected) {
        Billing b(getCurrentQuoteId());
        QString textButton = b.isBilling() ? "la facture": "le devis";
        QString iconButton = b.isBilling() ? "bill": "quote";
        ui->btnEditDoc->setText("Éditer "+textButton);
        ui->btnEditDoc->setIcon(QIcon(":icons/img/add_"+iconButton));
        ui->btnRemoveDoc->setText("Supprimer "+textButton);
        ui->btnRemoveDoc->setIcon(QIcon(":icons/img/remove_"+iconButton));
    } else {
        ui->btnEditDoc->setText("Éditer le document");
        ui->btnEditDoc->setIcon(QIcon(":icons/edit"));
        ui->btnRemoveDoc->setText("Supprimer le document");
        ui->btnRemoveDoc->setIcon(QIcon(":icons/edit"));
    }
}

void MainWindow::updateUser()
{
    ui->wdgUserData->printUserData();
}

void MainWindow::updateFolders()
{
    User* user = new User(1);
    user->updateFolders();
}

}

