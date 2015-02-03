#include "customerdatawidget.h"
#include "ui_customerdatawidget.h"

CustomerDataWidget::CustomerDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerDataWidget)
{
    ui->setupUi(this);
    hide();
}

CustomerDataWidget::~CustomerDataWidget()
{
    delete ui;
}

void CustomerDataWidget::printUserData()
{
    show();
    User *user = new User(1);
    ui->lbFax->hide();
    ui->lbTitleFax->hide();

    setLabel(ui->lbCompany, user->getCompany());
    setLabel(ui->lbName, user->getLastname()+ " " + user->getFirstname());
    setLabel(ui->lbPhone, user->getPhone(), ui->lbTitlePhone);
    setLabel(ui->lbMobilePhone, user->getMobilePhone(), ui->lbTitleMobile);
    setLabel(ui->lbEmail, "<a href=\"mailto:" + user->getEmail() + "\">"
             + user->getEmail() + "</a>");
    setLabel(ui->lbAddress, user->getAddress());
    setLabel(ui->lbPostalCodeCityCountry,user->getPostalCode()
             + " " + user->getCity());

}

void CustomerDataWidget::printInformations(int id)
{
    show();
    Customer *custom = new Customer(id);
    setLabel(ui->lbCompany, custom->getCompany());
    setLabel(ui->lbName, custom->getLastnameReferent()+ " " + custom->getFirstnameReferent());
    setLabel(ui->lbPhone, custom->getPhone(), ui->lbTitlePhone);
    setLabel(ui->lbMobilePhone, custom->getMobilePhone(), ui->lbTitleMobile);
    setLabel(ui->lbEmail, "<a href=\"mailto:" + custom->getEmail() + "\">"
             + custom->getEmail() + "</a>");
    setLabel(ui->lbAddress, custom->getAddress());
    setLabel(ui->lbPostalCodeCityCountry,custom->getPostalCode()
             + " " + custom->getCity());
    setLabel(ui->lbFax, custom->getFax(), ui->lbTitleFax);

}

void CustomerDataWidget::setLabel(QLabel* lbValue, QString s, QLabel* lbLabel)
{
    if(s != "") {
        lbValue->setText(s);
        lbValue->show();
        if(lbLabel != 0) {
            lbLabel->show();
        }
    } else {
        if(lbLabel != 0) {
            lbLabel->hide();
        }
        lbValue->hide();
    }
}
