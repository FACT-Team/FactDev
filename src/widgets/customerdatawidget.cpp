#include "customerdatawidget.h"
#include "ui_customerdatawidget.h"
#include "models/customer.h"
#include "models/user.h"

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
    ui->lbCompany->setText(user->getCompany());
    ui->lbName->setText(user->getLastname()+ " " + user->getFirstname());
    ui->lbPhone->setText(user->getPhone());
    ui->lbMobilePhone->setText(user->getMobilePhone());
    ui->lbEmail->setText("<a href=\"mailto:" + user->getEmail() + "\">"
                         + user->getEmail() + "</a>");
    ui->lbAddress->setText(user->getAddress());
    ui->lbPostalCodeCityCountry->setText(user->getPostalCode()
                                         + " " + user->getCity());
    ui->lbFax->hide();
}

void CustomerDataWidget::printInformations(int id)
{
    show();
    Customer *custom = new Customer(id);
    ui->lbAddress->setText(custom->getAddress());
    ui->lbCompany->setText(custom->getCompany());
    ui->lbEmail->setText("<a href=\"mailto:" + custom->getEmail() + "\">"
                         + custom->getEmail() + "</a>");
    ui->lbName->setText(custom->getLastnameReferent() + " "
                        + custom->getFirstnameReferent());
    ui->lbPhone->setText(custom->getPhone());
    ui->lbMobilePhone->setText(custom->getMobilePhone());
    ui->lbFax->setText(custom->getFax());
    ui->lbPostalCodeCityCountry->setText(custom->getPostalCode()
                                         + " " + custom->getCity()
                                         + ", " + custom->getCountry());
}
