#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database/customerdatabase.h"
#include "dialogs/dialogaddcustomer.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateTable();
    updateTree();
    ui->tblCustomers->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tblCustomers, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(openContextualMenu(const QPoint &)));}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCustomer()
{
    DialogAddCustomer win;
    if(win.exec()) {        // Ouverture de la fenêtre pour ajouter/modifier un client
        qDebug() << "accept";
        updateTable();
        updateTree();
    } else {

    }

}

void MainWindow::openContextualMenu(const QPoint point)
{
    QMenu* menu = new QMenu(this);
    QAction* deleteBilan = new QAction("Ouvrir le client", this);
    QAction* editBilan = new QAction("Modifier le client", this);
    QAction* pdfBilan = new QAction("Supprimer le client", this);

    QIcon icon;
    //icon.addFile(QStringLiteral(":/icones/pdf"), QSize(), QIcon::Normal, QIcon::Off);
    //pdfBilan->setIcon(icon);
    //icon.addFile(QStringLiteral(":/icones/editer"), QSize(), QIcon::Normal, QIcon::Off);
    //editBilan->setIcon(icon);
    //icon.addFile(QStringLiteral(":/icones/non"), QSize(), QIcon::Normal, QIcon::Off);
    //
    deleteBilan->setIcon(icon);
    menu->addAction(pdfBilan);
    menu->addAction(editBilan);
    menu->addAction(deleteBilan);
    QPoint buffPoint = point;
    buffPoint.setX(point.x()+35);
    buffPoint.setY(point.y()+35);
   menu->exec(ui->tblCustomers->mapToGlobal(buffPoint));
}

void MainWindow::updateTable()
{
    ui->tblCustomers->setModel(CustomerDatabase::instance()->getCustomersTable());
    ui->tblCustomers->hideColumn(0);
    ui->tblCustomers->setColumnWidth(0, 100);
    ui->tblCustomers->setColumnWidth(1, 100);
    ui->tblCustomers->setColumnWidth(2, 100);
    ui->tblCustomers->setColumnWidth(3, 150);
    ui->tblCustomers->setColumnWidth(4, 200);
}

void MainWindow::updateTree()
{
    ui->trCustomers->setModel(CustomerDatabase::instance()->getCustomersTree());
}

