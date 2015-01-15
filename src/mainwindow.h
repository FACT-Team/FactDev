#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QModelIndex>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int getCurrentCustomerId();
public slots:
    void addCustomer();
    void editCustomer();
    void removeCustomer();
    void openCustomer();
    void editUser();
    void search(QString);
    void search();
    void updateUserData();
    void addProject();
    void changeCustomer();
private slots:
    void openContextualMenuTable(const QPoint point);
    void openContextualMenuTree(const QPoint point);
    void changeCustomerTree(QModelIndex index);
    void changeCustomerTree();
private:
    void updateTable(QString filter="");
    void updateTree(QString filter="");

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
