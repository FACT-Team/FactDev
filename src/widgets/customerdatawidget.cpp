#include "customerdatawidget.h"
#include "ui_customerdatawidget.h"
#include "models/customer.h"

CustomerDataWidget::CustomerDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerDataWidget)
{
    ui->setupUi(this);
}

CustomerDataWidget::~CustomerDataWidget()
{
    delete ui;
}

void CustomerDataWidget::printInformations(int id)
{
    Customer *custom = new Customer(id);
    ui->lbAddress->setText(custom->getAddress());
    ui->lbCompany->setText("<strong>" + custom->getCompany() + "</strong>");
    ui->lbEmail->setText("<a href=\"mailto:" + custom->getEmail() + "\">" + custom->getEmail() + "</a>");
    ui->lbName->setText(custom->getLastnameReferent() + " " + custom->getFirstnameReferent());
    ui->lbPhone->setText("Fixe\t" + custom->getPhone());
    ui->lbMobilePhone->setText("Mobile\t" + custom->getMobilePhone());
    ui->lbFax->setText("Fax\t" +custom->getFax());
    ui->lbPostalCodeCityCountry->setText(custom->getPostalCode() + " " + custom->getCity() + ", " + custom->getCountry());
}
