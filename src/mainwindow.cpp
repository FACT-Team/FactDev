#include <QStandardPaths>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exceptions/fileexception.h"

using namespace Utils;

namespace Gui {
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
        SLOT(openContextupdualMenuTree(const QPoint &)));

    updateUser();
    updateButtons();
    updateFolders();
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
    QModelIndex index = ui->tblCustomers->currentIndex();
    AddProjectDialog *addProjectDialog;
    if(ui->stackedWidget->currentIndex() == 1) {
        addProjectDialog = new AddProjectDialog(index.row(), 0, 0);
        addProjectDialog->fillFields();
    } else {
        addProjectDialog = new AddProjectDialog(0, 0, 0);
    }
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
    if (QMessageBox::warning(
        this,
        "Suppression d'"
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
        updateTableCustomers("");
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
    AddQuoteDialog *editDocDialog(0);
    Billing b(getCurrentQuoteId());
    if (b.isBilling()) {
        editDocDialog = new AddQuoteDialog(
            true, getCurrentCustomerId(),getCurrentQuoteId());
    } else {
        editDocDialog = new AddQuoteDialog(
            false, getCurrentCustomerId(),getCurrentQuoteId());
    }

    if (editDocDialog->exec()) {
        updateTableBillings(getCurrentProjectId());
        updateTree();
        changeCustomerTable();
        ui->trCustomers->expand(ui->trCustomers->currentIndex());
        changeProjectsTable();
        ui->trCustomers->expand(ui->trCustomers->currentIndex());
        //ui->stackedWidget->setCurrentIndex(1); // if we remove te project in bill return to projects list
    }
    delete editDocDialog;
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

void MainWindow::search(QString text)
{
    Search s;
    QString styleSearchBackground =
	"background: url(:/icons/searchMini);"
	"background-position: right;"
	"background-repeat: no-repeat; "
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
    s.setSearchInProjects(ui->chkProjectName->isChecked());
    s.setSearchInContributories(ui->chkContributory->isChecked());
    s.setSearchInBillsQuotes(ui->chkBillQuote->isChecked());
    s.setText(text);

    updateUI(s.getFilter());
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
        break;
    }
    updateButtons();
}

void MainWindow::changeCustomerTable()
{
    ui->wdgCustomerData->printInformations(getCurrentCustomerId());
    int row = ui->tblCustomers->currentIndex().row();
    QModelIndex index(rootTree());

    for (int i = 0 ; i <= row ; ++i) {
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

        break;
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

/*
void MainWindow::quotesProject()
{
    ui->stackedWidget->setCurrentIndex(2);
    updateTableBillings(getCurrentProjectId());
    updateButtons();
}

void MainWindow::editQuote()
{
    if(ui->tblQuotes->selectionModel()->hasSelection()) {
        AddQuoteDialog addquotedialog(
                    false, getCurrentCustomerId(),getCurrentQuoteId());
        addquotedialog.exec();
        updateUI();
    }
}
*/

void MainWindow::updateUI(QString filter)
{
    if (ui->tblCustomers->model() != NULL) {
        delete ui->tblCustomers->model();
    }
    updateTableCustomers(filter);

    if (ui->tblProjects->model() != NULL) {
        delete ui->tblProjects->model();
    }
    updateTableProjects(getCurrentCustomerId());

    if (ui->tblQuotes->model() != NULL) {
        delete ui->tblQuotes->model();
    }
    updateTableBillings(getCurrentProjectId());

    if (ui->trCustomers->model() != NULL) {
        delete ui->trCustomers->model();
    }
    updateTree(filter);

    updateButtons();
    updateUser();
    updateFolders();

}

void MainWindow::search() {
    emit search(ui->leSearch->text());
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
    ui->trCustomers->setModel(
        Databases::CustomerDatabase::instance()->getTree(filter));
    //ui->trCustomers->header()->close();
}

void MainWindow::updateButtons()
{
    if (ui->stackedWidget->currentIndex() == 0
            && ui->tblCustomers->currentIndex().row() > -1
            && ui->tblCustomers->selectionModel()->hasSelection()) {
        ui->btnEdit->setEnabled(true);
        ui->btnDelCustomer->setEnabled(true);
    } else if (ui->tblCustomers->currentIndex().row() == -1
               && !ui->tblCustomers->selectionModel()->hasSelection()) {
        ui->btnEdit->setEnabled(false);
        ui->btnDelCustomer->setEnabled(false);
        ui->trCustomers->setCurrentIndex(rootTree());
    }

    if ((ui->stackedWidget->currentIndex() == 1
            || ui->stackedWidget->currentIndex() == 2)
            && ui->tblProjects->currentIndex().row() > -1
            && ui->tblProjects->selectionModel()->hasSelection()) {
        ui->actionNewQuote->setEnabled(true);
        ui->actionNewBill->setEnabled(true);
        ui->wdgTblProjectsToolBar->updateBtn(true);
    } else {
        ui->wdgTblProjectsToolBar->updateBtn(false);
        ui->actionNewQuote->setEnabled(false);
        ui->actionNewBill->setEnabled(false);
    }

    if (ui->stackedWidget->currentIndex() == 2
            && ui->tblQuotes->currentIndex().row() > -1
            && ui->tblQuotes->selectionModel()->hasSelection()) {
        Billing b(getCurrentQuoteId());
        if (b.isBilling()) {
            ui->btnEditDoc->setText("Éditer la facture");
            ui->btnEditDoc->setIcon(QIcon(":icons/img/add_bill"));
            ui->btnRemoveDoc->setText("Supprimer la facture");
            ui->btnRemoveDoc->setIcon(QIcon(":icons/img/remove_bill"));
        } else {
            ui->btnEditDoc->setText("Éditer le devis");
            ui->btnEditDoc->setIcon(QIcon(":icons/img/add_quote"));
            ui->btnRemoveDoc->setText("Supprimer le devis");
            ui->btnRemoveDoc->setIcon(QIcon(":icons/img/remove_quote"));
        }
        ui->btnRemoveDoc->setEnabled(true);
        ui->btnEditDoc->setEnabled(true);
        ui->btnLatex->setEnabled(true);
    } else {
        ui->btnEditDoc->setText("Éditer le document");
        ui->btnEditDoc->setIcon(QIcon(":icons/edit"));
        ui->btnEditDoc->setEnabled(false);
        ui->btnRemoveDoc->setText("Supprimer le document");
        ui->btnRemoveDoc->setIcon(QIcon(":icons/edit"));
        ui->btnRemoveDoc->setEnabled(false);
        ui->btnLatex->setEnabled(false);
    }
}

void MainWindow::updateUser()
{
    ui->wdgUserData->printUserData();
}

void MainWindow::updateFolders()
{
    User* user = new User(1);
    Customer customer;
    Project p1;
    Project p2;
    QString path;
    QString folder;
    QDir directory;

    if (user->getWorkspacePath().isEmpty()) {
        user->setWorkspacePath(
            QDir::homePath() + "/" +
            QStandardPaths::displayName(QStandardPaths::DocumentsLocation));
    }
    if (user->getWorkspaceName().isEmpty()) {
        user->setWorkspaceName("FactDev");
    }
    path = user->getWorkspacePath();
    folder = user->getWorkspaceName();
    directory.setPath(path);

    path = makeDirectory(directory, path, folder);

    for (auto c = _hierarchy.getCustomers().cbegin();
         c != _hierarchy.getCustomers().cend();
         ++c ) {
        customer = c.value();
        folder = customer.getPath();

        path = makeDirectory(directory, path, folder);

        for (auto p = _hierarchy.getProjects().cbegin();
             p != _hierarchy.getProjects().cend();
             ++p ) {
            p1 = *p.value();
            p2 = *c.key();

            if (p1 == p2) {
                if ((*p.key()).isBilling()) {
                    folder = "Factures";
                } else {
                    folder = "Devis";
                }
                path  = makeDirectory(directory, path, folder);
            }

            path = user->getWorkspacePath()
                    + "/" + user->getWorkspaceName() + "/" + customer.getPath();
            directory.setPath(path);
        }
        path = user->getWorkspacePath() + "/" + user->getWorkspaceName();
        directory.setPath(path);
    }

    delete user;
}

QString MainWindow::makeDirectory(QDir &directory,
                                  const QString path, const QString folder) {

    if (!directory.cd(path + "/" + folder)) {
        if (!directory.mkdir(folder)) {
            throw new FileException(
                        "Impossible de créer le répertoire de travail",
                        "makeDirectory::" + path + "/" + folder,
                        directory.currentPath(),
                        1.1);
        }

    }
    directory.setPath(path + "/" + folder);
    return path + "/" + folder;
}

}

