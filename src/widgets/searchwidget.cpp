#include "searchwidget.h"
#include "ui_searchwidget.h"
#include "models/search.h"
#include "database/customerdatabase.h"
searchWidget::searchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchWidget)
{
    ui->setupUi(this);
    updateTable();
}

searchWidget::~searchWidget()
{
    delete ui;
}

int searchWidget::getCurrentCustomerId()
{
    QModelIndex idCell = ui->tblSearch->model()->index(
                ui->tblSearch->currentIndex().row(), 0);

    return ui->tblSearch->model()->itemData(idCell).value(0).toInt();
}

void searchWidget::search(QString text)
{
    Search s;
    s.setGroupFilter(false);
    s.setSearchInCompanies(true);
    s.setSearchInReferentLastname(true);
    s.setText(text);
    updateTable(s.getFilter());

    QString styleSearchBackground =
            "background: url(:/icons/searchMini);"
            "background-position: right;"
            "background-repeat: no-repeat;     "
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
}

void searchWidget::updateTable(QString filter)
{
    ui->tblSearch->setModel(CustomerDatabase::instance()->getCustomersTable(filter));
    ui->tblSearch->hideColumn(0);
    ui->tblSearch->hideColumn(4);
    ui->tblSearch->hideColumn(5);
    ui->tblSearch->setColumnWidth(1, 100);
    ui->tblSearch->setColumnWidth(2, 100);
    ui->tblSearch->setColumnWidth(3, 200);
}
