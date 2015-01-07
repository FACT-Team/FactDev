#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database/database.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Database::instance();
}

MainWindow::~MainWindow()
{
    delete ui;
}
