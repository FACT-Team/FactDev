#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QModelIndex>
#include <QTableView>

#include "itemtype.h"

#include "database/projectdatabase.h"
#include "database/billingdatabase.h"

#include "widgets/popup.h"
#include "widgets/customercontextualmenu.h"

#include "dialogs/messagebox/messagebox.h"
#include "dialogs/userdatadialog.h"
#include "dialogs/dialogaddcustomer.h"
#include "dialogs/addprojectdialog.h"
#include "dialogs/addquotedialog.h"

#include "models/search.h"

namespace Ui {
class MainWindow;
}


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
     * @brief MainWindow::isTreeRoot return if the node selected in the
     * tree is the root
     * @return boolean
     */
    bool isTreeRoot();
    /**
     * @brief MainWindow::isCustomerItemTree return if the node selected in the
     * tree is a customer
     * @return boolean
     */
    bool isCustomerItemTree();
    /**
     * @brief MainWindow::isProjectItemTree return if the node selected in the
     * tree is a project
     * @return boolean
     */
    bool isProjectItemTree();

    //TODO
    bool isQuoteItemTree();
    void demo();
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
     * @brief MainWindow::addQuote open window to add a new quote
     * @see AddQuoteDialog
     */
    void addQuote();
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
     * @brief MainWindow:search call search(QString)
     */
    void search();
    /**
     * @brief MainWindow::newProject Create a new project for a customer
     * @see AddProjectDialog
     */
    void newProject();
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
     * @brief MainWindow::aboutFactDev() show FactDev's details (FactDev Software)
     */
    void aboutFactDev();
    /**
     * @brief MainWindow::aboutIcons() show icons's details
     */
    void aboutIcons();

    /**
     * @brief updateBtn Update all button to disable or enabled its
     */
    void updateBtn(void);

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
     * @brief MainWindow::changeCustomerTable calls changeCustomerTable
     */
    void changeCustomerTable();
    /**
     * @brief MainWindow::changeProjectsTable changes projects with the <i>index</i>
     * of the customer in table of customers
     */
    void changeProjectsTable();
    /**
     * @brief MainWindow::backToCustomersTable displays the customers table
     */
    void backToCustomersTable();
    /**
     * @brief MainWindow::backToProjectsTable displays the projects table
     */
    void backToProjectsTable();
    /**
     * @brief MainWindow::quotesProject displays quotes of a project with the <i>index</i>
     * of the project in the table of projects
     */
    void quotesProject();

private:
    /**
     * @brief MainWindow::updateTable Update the table view
     * (just client in the first version)
     */
    void updateTableCustomers(QString filter="");
    /**
     * @brief MainWindow::updateTableProjects Update the table of projects view
     * @param filter Only projects corresponding with the filter are selected
     */
    void updateTableProjects(const int pId = 0);


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
     */
    void updateTableBillings(const int idProject);
    /**
     * @brief MainWindow::removeItem Remove the <i>item</i> selected in the
     * table <i>tbl</i>
     * @param tbl a table
     * @param item an item in the table <i>tbl</i>
     */
    void removeItem(QTableView* tbl, ItemType item);
    /**
     * @brief MainWindow::getCurrentTableId Get the ID of the item selected in
     * the  tableview <i>tbl</i>
     * @return id of the item selected
     */
    int getCurrentTableId(QTableView *tbl);

    Ui::MainWindow *ui; //!< ui
};

#endif // MAINWINDOW_H
