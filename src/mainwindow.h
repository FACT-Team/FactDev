#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addCustomer();
    void editCustomer();
    void removeCustomer();
    void openCustomer();
    void search(QString);
    void search();
private slots:
    void openContextualMenuTable(const QPoint point);
    void openContextualMenuTree(const QPoint point);
private:
    void updateTable(QString filter="");
    void updateTree(QString filter="");
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
