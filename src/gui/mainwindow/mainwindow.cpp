#include <QStandardPaths>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gui/dialogs/startedwindowsdialog.h"
#include <QDesktopWidget>
using namespace Utils;

namespace Gui {
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setupUi();
    setupSignalsSlots();
    QSettings settings("FACT Team", "FactDev");
    Databases::AccessDatabase::init();
    if(!Databases::AccessDatabase::_exists/* | !QFile(settings.value("dbPath").toString()+"/"+Parameters::DB_FILENAME).exists()*/) {
        StartedWindowsDialog w;
        w.exec();
    }
    updateUser();
    showMaximized();
    responsiveCustomerTable();
}

void MainWindow::setupUi()
{
    ui->setupUi(this);

    QDesktopWidget screen;
    setMaximumSize(screen.width(), screen.height());

    _searchDock = new Docks::SearchDock();
    addDockWidget(Qt::LeftDockWidgetArea, _searchDock);
    addDockWidget(Qt::LeftDockWidgetArea, ui->dockCustomers);

    ui->stackedWidget->setCurrentIndex(0);
    updateTableCustomers();
    updateTree();
    updateUser();
    updateButtons();
    User(1).updateFolders();
}

void MainWindow::setupSignalsSlots()
{
    connect(ui->tblCustomers,SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(openContextualMenuTable(const QPoint &)));
    connect(_searchDock,
            SIGNAL(textChanged(QString)),
            this,
            SLOT(search(QString)));
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
        ui->tblCustomers->model()->index(
                ui->tblCustomers->currentIndex().row(), 1);

    return index.model()->itemData(index).value(0).toString();
}

QString MainWindow::getCurrentProjectName()
{
    QModelIndex index =
            ui->tblProjects->model()->index(ui->tblProjects->currentIndex().row(),1);
    return index.model()->itemData(index).value(0).toString();
}

void MainWindow::addCustomer()
{
    if (DialogAddCustomer().exec()) { // accept
        ui->stackedWidget->setCurrentIndex(0);
        updateTableCustomers();
        updateTree();        
    }
}

void MainWindow::addProject()
{
    AddProjectDialog *addProjectDialog =
            ui->stackedWidget->currentIndex() == 1 ?
                new AddProjectDialog(0, ui->tblCustomers->currentIndex().row())
              : new AddProjectDialog();

    if (addProjectDialog->exec()) {
        updateTableProjects(getCurrentCustomerId());
        updateTree();
        changeCustomerTable();
        User(1).updateFolders();
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
    if (AddQuoteDialog(isBilling, getCurrentCustomerId()).exec()) {
        updateTableBillings(getCurrentProjectId());
        updateTree();
        changeCustomerTable();
        ui->trCustomers->expand(ui->trCustomers->currentIndex());
        changeProjectsTable();
        ui->trCustomers->expand(ui->trCustomers->currentIndex());

        // For security and crash of the application
        // if we remove a project in a doc and we save it
        // or if we are in a project and we associate the doc with an other project
        // go back to the panel projectsTable
        // ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    switch (ui->stackedWidget->currentIndex()) {
        case 0:
            responsiveCustomerTable();
            break;
        case 1:
            responsiveProjectTable();
            break;
        case 2:
            responsiveBillingTable();
            break;
        default:
            responsiveCustomerTable();
    }


}

void MainWindow::responsiveCustomerTable()
{
    int w = ui->tblCustomers->width();

    ui->tblCustomers->resizeColumnsToContents();

    if (w > 650) {
        ui->tblCustomers->hideColumn(0);
        ui->tblCustomers->setColumnWidth(0, w*0.0);
        ui->tblCustomers->setColumnWidth(1, w*0.15);
        ui->tblCustomers->setColumnWidth(2, w*0.15);
        ui->tblCustomers->setColumnWidth(3, w*0.15);
        ui->tblCustomers->setColumnWidth(4, w*0.15);
        ui->tblCustomers->setColumnWidth(5, w*0.25);
        ui->tblCustomers->setColumnWidth(6, w*0.145);
    } else {
        ui->tblCustomers->hideColumn(0);
        ui->tblCustomers->setColumnWidth(0, 0);
        ui->tblCustomers->setColumnWidth(1, 200);
        ui->tblCustomers->setColumnWidth(2, 100);
        ui->tblCustomers->setColumnWidth(3, 150);
        ui->tblCustomers->setColumnWidth(4, 150);
        ui->tblCustomers->setColumnWidth(5, 280);
        ui->tblCustomers->setColumnWidth(6, 100);
    }
}


void MainWindow::responsiveProjectTable()
{
    int w = ui->tblProjects->width();

    if (w > 400) {
        ui->tblProjects->setColumnWidth(0, w*0.1);
        ui->tblProjects->setColumnWidth(1,w*0.15);
        ui->tblProjects->setColumnWidth(2, w*0.5);
        ui->tblProjects->setColumnWidth(3, w*0.125);
        ui->tblProjects->setColumnWidth(4, w*0.125);
        ui->tblProjects->setColumnWidth(5,w*0.095);
    } else {
        ui->tblProjects->setColumnWidth(0, 100);
        ui->tblProjects->setColumnWidth(1, 150);
        ui->tblProjects->setColumnWidth(2, 200);
        ui->tblProjects->setColumnWidth(3, 122);
        ui->tblProjects->setColumnWidth(4, 122);
        ui->tblProjects->setColumnWidth(5, 100);
    }
}

void MainWindow::responsiveBillingTable()
{
    int w = ui->tblQuotes->width();

    if (w > 700) {
        ui->tblQuotes->hideColumn(0);
        ui->tblQuotes->setColumnWidth(1, w*0.045);
        ui->tblQuotes->setColumnWidth(2, w*0.045);
        ui->tblQuotes->setColumnWidth(3, w*0.2);
        ui->tblQuotes->setColumnWidth(4, w*0.5);
        ui->tblQuotes->setColumnWidth(5, w*0.15);
        ui->tblQuotes->setColumnWidth(6, w*0.05);
    } else {
        ui->tblQuotes->hideColumn(0);
        ui->tblQuotes->setColumnWidth(1, 40);
        ui->tblQuotes->setColumnWidth(2, 40);
        ui->tblQuotes->setColumnWidth(3, 200);
        ui->tblQuotes->setColumnWidth(4, 250);
        ui->tblQuotes->setColumnWidth(5, 130);
        ui->tblQuotes->setColumnWidth(6, 50);
    }
}



void MainWindow::billingIsPaid()
{
    Billing billing(this->getCurrentQuoteId());
    if (billing.isBilling() && !billing.isPaid()) {
        if (QMessageBox::warning(
                    this,
                    "Définir comme payée la facture N°"
                    + QString::number(billing.getNumber()),
                    "Attention, si vous validez cette facture comme payée "
                    "alors elle ne pourra plus être modifier.\n\n"
                    "Êtes-vous sûr de définir la facture n°"
                    + QString::number(billing.getNumber()) + " comme payée ?",
                    "Valider",
                    "Annuler") == 0)
        {
            billing.setIsPaid(true);
            billing.commit();
            updateButtons();
            updateTableBillings(getCurrentProjectId());
            updateCostAndTurnover();
        }
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
            // For turnover customer
            updateTableCustomers("",
                                 ui->tblCustomers->currentIndex().row());
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
    if (DialogAddCustomer(getCurrentCustomerId()).exec()) {
        updateTableCustomers();
        updateTree();
        ui->trCustomers->setCurrentIndex(rootTree());
    }
}

void MainWindow::editProject() {
    int row = ui->tblProjects->currentIndex().row();

    if (AddProjectDialog(getCurrentProjectId(), row).exec()) {
        updateTableProjects(getCurrentCustomerId());
        updateTree();
        changeCustomerTable();
        ui->trCustomers->expand(ui->trCustomers->currentIndex());
    }
}

void MainWindow::editUser()
{
    if (UserDataDialog().exec()) {
        updateUser();
    }
}

void MainWindow::editDoc()
{
    AddQuoteDialog editDocDialog(
                Billing(getCurrentQuoteId()).isBilling(),
                                 getCurrentCustomerId(),
                                 getCurrentQuoteId(),
                                 false);

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

void MainWindow::copyDoc()
{
    AddQuoteDialog copyDocDialog(
                Billing(getCurrentQuoteId()).isBilling(),
                getCurrentCustomerId(),
                getCurrentQuoteId(),
                true);

    if (copyDocDialog.exec()) {
        updateTableBillings(getCurrentProjectId());
        updateTree();
    }
}

void MainWindow::openPdf()
{
    QModelIndex ls = ui->tblQuotes->selectionModel()->selectedRows().first();
    int pid = ui->tblQuotes->model()->data(ls, Qt::DisplayRole).toInt();
    Billing bill(pid);
    if(!QFile(bill.getPath()+".pdf").exists()) {
        bill.generatePdf();
    }
    QFileInfo pdf(bill.getPath()+".pdf");

    QDesktopServices::openUrl(QUrl("file:///"+pdf.absoluteFilePath()));

}

void MainWindow::computeTurnover()
{
    ComputeTurnoverDialog cp;

    cp.exec();
}

void MainWindow::globalStatistics()
{
    StatisticsDialog(true).exec();
}

void MainWindow::customerStatistics()
{
    StatisticsDialog(false, getCurrentCustomerId()).exec();
}

void MainWindow::search(QString text)
{
    ui->stackedWidget->setCurrentIndex(0);
    updateTableCustomers(text, ui->tblCustomers->currentIndex().row());
    updateTree(text);
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
        responsiveCustomerTable();
        break;
    case 1:         // Customer
        ui->tblCustomers->selectRow(idRow-1);
        ui->wdgCustomerData->printInformations(getCurrentCustomerId());
        ui->trCustomers->collapseAll();
        ui->trCustomers->expand(index);
        customersTableToProjectsTable();
        ui->stackedWidget->setCurrentIndex(1);
        responsiveCustomerTable();
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
        Log::instance(WARNING) << "MainWindow::changeTree – "
                                  "I don't know what I'm doing here… ";
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
    responsiveCustomerTable();
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
    responsiveProjectTable();
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
    responsiveBillingTable();
    updateButtons();
}

void MainWindow::customersTableToProjectsTable()
{
    updateTableProjects(getCurrentCustomerId());
    ui->lblProjects->setText("Projets de <b>"
                             + getCurrentCustomerName()+"</b>");

    ui->stackedWidget->setCurrentIndex(1);
    QModelIndex index(ui->trCustomers->currentIndex());
    ui->trCustomers->expand(index);
    responsiveProjectTable();
    updateButtons();
}

void MainWindow::projectsTableToDocsTable()
{
    ui->stackedWidget->setCurrentIndex(2);
    updateTableBillings(getCurrentProjectId());
    ui->trCustomers->expand(QModelIndex(ui->trCustomers->currentIndex()));
    responsiveBillingTable();
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
        Log::instance(WARNING) << "MainWindow::findParent – "
                                  "I don't know what I'm doing here… ";
    }

    return parent;
}

void MainWindow::backToCustomersTable()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->trCustomers->collapseAll();
    changeCustomerTable();
    responsiveCustomerTable();
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
    responsiveProjectTable();
}

void MainWindow::updateUI(QString filter)
{
    updateTableCustomers(filter, ui->tblCustomers->currentIndex().row());

    updateTableProjects(getCurrentCustomerId(),
                        ui->tblProjects->currentIndex().row());

    updateTableBillings(getCurrentProjectId());

    updateTree(filter);

    updateButtons();
    updateUser();
    User(1).updateFolders();
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

    if (row > -1) {
        ui->tblCustomers->selectRow(row);
    } else {
        ui->tblCustomers->clearSelection();
    }
    responsiveCustomerTable();
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
    responsiveProjectTable();
}

void MainWindow::updateTableBillings(const int idProject, const int row)
{
    Utils::pointers::deleteIfNotNull(ui->tblQuotes->model());
    ui->tblQuotes->setModel(
        Databases::BillingDatabase::instance()->getBillingsTable(idProject));
    ui->lblDocs->setText("Factures et Devis du projet <b>"
                           + getCurrentProjectName()
                           + "</b>");


    if (row > -1) {
        ui->tblQuotes->selectRow(row);
    } else {
        ui->tblQuotes->clearSelection();
    }
    responsiveBillingTable();
}

void MainWindow::updateCostAndTurnover()
{
    // For project Cost
    updateTableProjects(
                getCurrentCustomerId(),
                ui->tblProjects->currentIndex().row());
    // For turnover customer
    updateTableCustomers(
                "",
                ui->tblCustomers->currentIndex().row());
}

void MainWindow::updateTree(QString filter)
{
    if (ui->trCustomers->model() != NULL) {
        delete ui->trCustomers->model();
    }
    ui->trCustomers->setModel(
                Databases::CustomerDatabase::instance()->getTree(filter));
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
    bool isBillingPaid = false;
    bool customerSelected = ui->tblCustomers->currentIndex().row() > -1
            && ui->tblCustomers->selectionModel()->hasSelection();

    ui->btnEdit->setEnabled(canModify);
    ui->btnDelCustomer->setEnabled(canModify);

    if(ui->tblCustomers->currentIndex().row() == -1
            && !ui->tblCustomers->selectionModel()->hasSelection()) {
        ui->trCustomers->setCurrentIndex(rootTree());
    }

    ui->actionNewQuote->setEnabled(canAdd);
    ui->actionNewBill->setEnabled(canAdd);
    ui->actCustomerStatistics->setEnabled(customerSelected);
    ui->wdgTblProjectsToolBar->updateBtn(canAdd);
    ui->btnRemoveDoc->setEnabled(billingIsSelected);
    ui->btnEditDoc->setEnabled(billingIsSelected);
    ui->btnPdf->setEnabled(billingIsSelected);
    ui->btnCopyDoc->setEnabled(billingIsSelected);

    if (billingIsSelected) {

        Billing b(getCurrentQuoteId());
        QString textButton = b.isBilling() ? "la facture": "le devis";
        QString iconButton = b.isBilling() ? "bill": "quote";
        isBillingPaid = b.isBilling() && b.isPaid();
        ui->btnEditDoc->setText("Éditer "+textButton);
        ui->btnEditDoc->setIcon(QIcon(":icons/img/add_"+iconButton));
        ui->btnRemoveDoc->setText("Supprimer "+textButton);
        ui->btnRemoveDoc->setIcon(QIcon(":icons/img/remove_"+iconButton));
        ui->btnCopyDoc->setText("Copier "+textButton);
        ui->btnCopyDoc->setIcon(QIcon(b.isBilling() ? ":icons/img/copy_bill.png"
                                                    : ":icons/img/copy_quote"));

        if (isBillingPaid || !b.isBilling()) {
            ui->btnBillingIsPaid->setEnabled(false);
            if (isBillingPaid) {
                ui->btnRemoveDoc->setEnabled(false);
                ui->btnEditDoc->setEnabled(false);
            }
        } else {
            ui->btnBillingIsPaid->setEnabled(true);
        }
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

}

