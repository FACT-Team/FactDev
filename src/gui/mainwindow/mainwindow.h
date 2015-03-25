#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QModelIndex>
#include <QTableView>
#include <QDir>
#include <QDesktopServices>
#include <QUrl>

#include "utils/itemtype.h"
#include "utils/log.h"
#include "utils/hierarchicalsystem.h"

#include "database/projectdatabase.h"
#include "database/billingdatabase.h"
#include "database/accessdatabase.h"

#include "gui/widgets/popup.h"
#include "gui/widgets/customercontextualmenu.h"

#include "gui/dialogs/messagebox.h"
#include "gui/dialogs/userdatadialog.h"
#include "gui/dialogs/dialogaddcustomer.h"
#include "gui/dialogs/addprojectdialog.h"
#include "gui/dialogs/addquotedialog.h"
#include "gui/dialogs/computeturnoverdialog.h"
#include "gui/docks/searchdock.h"


#include "exceptions/fileexception.h"

#include "utils/pointers.h"
using namespace Gui::Dialogs;

namespace Ui {
class MainWindow;
}

/**
 * Classes for Graphical User Interface
 */
namespace Gui {

/**
 * @author Everybody
 * @brief The MainWindow class Main Window of the software
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow: Construct a window
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
     * @brief MainWindow::getCurrentCustomerId get the selected customer
     * @return id of the selected customer
     */
    int getCurrentCustomerId();

    /**
     * @brief MainWindow::getCurrentProjectId get the selected project id
     * @return id of the selected project
     */
    int getCurrentProjectId();

    /**
     * @brief MainWindow::getCurrentQuoteId get the selected quote id
     * @return id of the selected quote
     */
    int getCurrentQuoteId();

    /**
     * @brief MainWindow::getCurrentCustomerName get the selected customer name
     * in the customers' table
     * @return name of the selected customer
     */
    QString getCurrentCustomerName();

    /**
     * @brief MainWindow::getCurrentProjectName get the selected project name in
     * the table of projects
     * @return name of the selected project
     */
    QString getCurrentProjectName();

    /**
     * @brief MainWindow::treeLevel return the level of the node selected in the
     *  tree
     * @return integer, depth of the item in tree
     */
    int treeLevel();
    /**
     * @brief MainWindow::rootTree return the root of the tree "Tous les
     * clients"
     * @return QModelIndex
     */
    QModelIndex rootTree();
    /**
     * @brief MainWindow::addDoc open window to add a new document
     * @param bool quote or bill
     * @see addBill addQuote
     */
    void addDoc(bool isBilling);

    /**
     * @brief MainWindow::resizeEvent Resize central TableView when you resize
     * the <b>MainWindow</b>
     * @param event Resize event
     */
    void resizeEvent(QResizeEvent *event);

    /**
     * @brief MainWindow::responsiveCustomerTable Resize the Customer TableView
     * according it resolution
     */
    void responsiveCustomerTable();
    /**
     * @brief MainWindow::responsiveProjectTable Resize the Project TableView
     * according it resolution
     */
    void responsiveProjectTable();

    /**
     * @brief MainWindow::responsiveBillingTable Resize the Billing TableView
     * according it resolution
     */
    void responsiveBillingTable();

public slots:
    /**
     * @brief MainWindow::addCustomer open window to add a new customer
     */
    void addCustomer();
    /**
     * @brief MainWindow::editCustomer open window to modify a customer
     */
    void editCustomer();
    /**
     * @brief MainWindow::removeCustomer open a popup to confirm the deletion
     * of a customer, if ok remove the customer
     */
    void removeCustomer();
    /**
     * @brief MainWindow::archiveCustomer open a pop-up to confirm the
     * archiving of the customer, if ok archive the customer
     */
    void archiveCustomer();
    /**
     * @brief MainWindow::addQuote open window to add a new quote
     * @see AddQuoteDialog
     */
    void addQuote();
    /**
     * @brief MainWindow::addBill open window to add a new bill
     * @see AddQuoteDialog
     */
    void addBill();
    /**
     * @brief MainWindow::billingIsPaid Define the current billing as "paid"
     */
    void billingIsPaid();
    /**
     * @brief MainWindow::editUser modify the user
     * @see UserDataDialog
     */
    void editUser();
    /**
     * @brief MainWindow::search launch a new search
     * @param s text in field
     */
    void search(QString s);
    /**
     * @brief MainWindow::addProject Create a new project for a customer
     * @see AddProjectDialog
     */
    void addProject();
    /**
     * @brief MainWindow::removeProject Remove a project for a customer
     */
    void removeProject(void);
    /**
     * @brief MainWindow::editProject Modify the customer project
     */
    void editProject(void);
    /**
     * @brief MainWindow::aboutQt show Qt's details
     */
    void aboutQt();
    /**
     * @brief MainWindow::aboutFact show FACT's details (FACT team)
     */
    void aboutFact();
    /**
     * @brief MainWindow::aboutFactDev() show FactDev's details (FactDev
     * Software)
     */
    void aboutFactDev();
    /**
     * @brief MainWindow::aboutIcons() show icons's details
     */
    void aboutIcons();
    /**
     * @brief updateButton Update all button to disable or enabled its
     */
    void updateButtons(void);

    /**
     * @brief MainWindow::editDoc Edit the quote or bill of the project
     */
    void editDoc();
    /**
     * @brief MainWindow::removeDoc Remove the quote or bill of the project
     */
    void removeDoc();

    /**
     * @brief MainWindow::copyDoc Copy all elements of a quote or a bill and
     * Display these elements in a new quote or bill
     */
    void copyDoc();

    /**
     * @brief MainWindow::openPdf Open the PDF file of the current Quote or
     * Billing selected in the TableView
     */
    void openPdf();

    /**
     * @brief MainWindow::computeTurnover open window to allow computation
     * of a period turnover
     */
    void computeTurnover();

private slots:
    /**
     * @brief MainWindow::openContextualMenuTable open contextual menu
     * on right click, on table
     * @param QPoint
     */
    void openContextualMenuTable(const QPoint point);
    /**
     * @brief MainWindow::openContextualMenuTree open contextual menu
     * on right click, on tree
     * @param QPoint
     */
    void openContextualMenuTree(const QPoint point);
    /**
     * @brief MainWindow::changeCustomerTree call changeCustomerTree
     */
    void changeTree();
    /**
     * @brief MainWindow::changeCustomerTable function to update the view
     * when we change the selected customer in tblCustomers
     */
    void changeCustomerTable();
    /**
     * @brief MainWindow::changeProjectsTable function to update the view
     * when we change the selected project in tblProjects
     */
    void changeProjectsTable();
    /**
     * @brief MainWindow::changeDocsTable function to update the view
     * when we change the selected doc in tblQuotes
     */
    void changeDocsTable();
    /**
     * @brief MainWindow::customersTableToProjectsTable changes projects with
     * the <i>index</i>
     * of the customer in table of customers
     */
    void customersTableToProjectsTable();
    /**
     * @brief MainWindow::backToCustomersTable displays the customers table
     */
    void backToCustomersTable();
    /**
     * @brief MainWindow::backToProjectsTable displays the projects table
     */
    void backToProjectsTable();
    /**
     * @brief MainWindow::projectsTableToDocsTable displays quotes of a project
     * with the <i>index</i>
     * of the project in the table of projects
     */
    void projectsTableToDocsTable();
    /**
     * @brief MainWindow::findParent return the parent of an item in tree
     * @return QModelIndex
     */
    QModelIndex findParent();

private:
    /**
     * @brief MainWindow::setupUi Set up of the User interface
     */
    void setupUi();

    /**
     * @brief MainWindow::setupSignalsSlots Set up Signals slots of the User
     * interface
     */
    void setupSignalsSlots();
    /**
     * @brief MainWindow::updateUI Update all components of the
     * <b>MainWindow</b>
     */
    void updateUI(QString filter="");

    /**
     * @brief MainWindow::updateTable Update the table view
     * (just client in the first version)
     * @param filter
     * @param row optional parameter for select the row in table
     */
    void updateTableCustomers(QString filter="", const int row = -1);
    /**
     * @brief MainWindow::updateTableProjects Update the table of projects view
     * @param filter Only projects corresponding with the filter are selected
     * @param row optional parameter for select the row in table
     */
    void updateTableProjects(const int pId = 0, const int row = -1);

    /**
     * @brief MainWindow::updateTree Update the tree view
     * (just client in the first version)
     */
    void updateTree(QString filter="");

    /**
     * @brief MainWindow::updateUser Update user data panel
     */
    void updateUser();

    /**
     * @brief MainWindow::updateTableBillings Update the table of
     * billings view
     * @param idProject Only billings corresponding to the idProject
     * @param row optional parameter for select the row in table
     */
    void updateTableBillings(const int idProject, const int row = -1);

    /**
     * @brief MainWindow::updateCostAndTurnover Update for the cost and turnover
     */
    void updateCostAndTurnover();

    /**
     * @brief MainWindow::removeItem Remove the <i>item</i> selected in the
     * table <i>tbl</i>
     * @param tbl a table
     * @param item an item in the table <i>tbl</i>
     */
    void removeItem(QTableView* tbl, Utils::ItemType item);

    /**
     * @brief MainWindow::getCurrentTableId Get the ID of the item selected in
     * the  tableview <i>tbl</i>
     * @return id of the item selected
     */
    int getCurrentTableId(QTableView *tbl);

    Ui::MainWindow *ui;             //!< User interface
    Docks::SearchDock* _searchDock; //!< Search dock of the user interface
};
}
#endif // MAINWINDOW_H
