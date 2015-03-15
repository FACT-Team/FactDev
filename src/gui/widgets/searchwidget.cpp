#include "searchwidget.h"
#include "ui_searchwidget.h"

namespace Gui {
namespace Widgets {
searchWidget::searchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchWidget)
{
    ui->setupUi(this);
    _isCustomerSelected = false;
    updateTable();
}

searchWidget::~searchWidget()
{
    delete ui;
}

int searchWidget::getCurrentCustomerId()
{
    if(_idCustomer != 0) {
    QModelIndex idCell = ui->tblSearch->model()->index(
                ui->tblSearch->currentIndex().row(), 0);

        return ui->tblSearch->model()->itemData(idCell).value(0).toInt();
    } else {
        return _idCustomer;
    }
}

void searchWidget::search(QString text)
{
    Models::Search s;
    s.setGroupFilter(false);
    s.setSearchInCompanies(true);
    s.setSearchInReferentLastname(true);
    s.setSearchInContributories(false);
    s.setSearchInProjects(false);
    s.setSearchInBillsQuotes(false);
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

void searchWidget::getCustomerData() {
    _isCustomerSelected = true;
    Models::Customer customer = Models::Customer(getCurrentCustomerId());

    ui->leCustomer->setText( customer.getFirstname() + " "
                            + customer.getLastname());
    emit selectCustomer();
}

void searchWidget::updateTable(QString filter) {

    ui->tblSearch->setModel(
            Databases::CustomerDatabase::instance()->getCustomersTable(filter));
    ui->tblSearch->hideColumn(0);
    ui->tblSearch->hideColumn(4);
    ui->tblSearch->hideColumn(5);
    ui->tblSearch->setColumnWidth(1, 200);
    ui->tblSearch->setColumnWidth(2, 120);
    ui->tblSearch->setColumnWidth(3, 120);

}
int searchWidget::getIdCustomer() const
{
    return _idCustomer;
}

void searchWidget::setIdCustomer(int idCustomer)
{
    _idCustomer = idCustomer;
}

bool searchWidget::isCustomerSelected() const
{
    return _isCustomerSelected || _idCustomer != 0;
}
void searchWidget::selectCustomer(int id) {
    ui->tblSearch->selectRow(id);
    getCustomerData();
}
}
}
