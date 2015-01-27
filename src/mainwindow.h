#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QModelIndex>
namespace Ui {
class MainWindow;
}

/**
 * @author
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
     * @brief MainWindow::isProject return if the node selected in the
     * tree is a customer or a project
     * @return true if it's a customer, false if it's a project
     */
    bool isCustomer();
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
     * @brief MainWindow::openCustomer open a customer and print his informations
     * @see CustomerDataWidget
     */
    void openCustomer();
    /**
     * @brief MainWindow::editUser modify the user
     * @see UserDataDialog
     */

    /**
     * @brief MainWindow::addQuote open window to add a new quote
     * @see AddQuoteDialog
     */
    void addQuote();

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
    void newProject(void);
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
     * @brief MainWindow::changeCustomerTree when customer changed in tree
     * update customer selected in table and his informations
     * @param index index of selected customer
     */
    void changeCustomerTree(QModelIndex index);
    /**
     * @brief MainWindow::changeCustomerTree call changeCustomerTree
     */
    void changeCustomerTree();
    /**
     * @brief MainWindow::changeCustomerTable when customer changed in table
     * update his informations
     * @param index index of selected customer
     */
    void changeCustomerTable(QModelIndex index);
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
     * @brief MainWindow::projectsCustomersTableTree displays projects of a customer
     * or all customers
     */
    void projectsCustomersTableTree();
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
    void updateTable(QString filter="");
    /**
     * @brief updateTableProjects Update the table of projects view
     * @param filter Only projects corresponding with the filter are selected
     */
    void updateTableProjects(const int pId);
    /**
     * @brief MainWindow::updateTree Update the tree view
     * (just client in the first version)
     */
    void updateTree(QString filter="");
    void updateUser();
    /**
     * @brief MainWindow::updateTableBillings Update the table of
     * billings view
     * @param idProject Only billings corresponding to the idProject
     */
    void updateTableBillings(const int idProject);

    Ui::MainWindow *ui; //!< ui
};

#endif // MAINWINDOW_H
