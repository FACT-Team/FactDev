#include "dialogs/dialogaddcustomer.h"
#include <QDebug>
#include "ui_dialogaddcustomer.h"

DialogAddCustomer::DialogAddCustomer(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddCustomer)
{
    ui->setupUi(this);

    if (id != 0) {
        _custom = Customer(id);
        fillFields(_custom);
    }
    _custom.setId(id);
}

void DialogAddCustomer::fillFields(Customer custom) {
    ui->leLastNameReferent->setText(_custom.getLastnameReferent());
    ui->leFirstNameReferent->setText(custom.getFirstnameReferent());
    ui->leCompany->setText(custom.getCompany());
    ui->leAddress->setText(custom.getAddress());
    ui->leCity->setText(custom.getCity());
    ui->lePostalCode->setText(custom.getPostalCode());
    ui->leCountry->setText(custom.getCountry());
    ui->leEmail->setText(custom.getEmail());
    ui->lePhone->setText(custom.getPhone());
    ui->leMobilePhone->setText(custom.getMobilePhone());
    ui->leFax->setText(custom.getFax());
}

void DialogAddCustomer::accept() {

    _custom.setLastnameReferent(ui->leLastNameReferent->text());
    _custom.setFirstnameReferent(ui->leFirstNameReferent->text());
    _custom.setCompany(ui->leCompany->text());
    _custom.setAddress(ui->leAddress->text());
    _custom.setCity(ui->leCity->text());
    _custom.setPostalCode(ui->lePostalCode->text());
    _custom.setCountry(ui->leCountry->text());
    _custom.setEmail(ui->leEmail->text());
    _custom.setPhone(ui->lePhone->text());
    _custom.setMobilePhone(ui->leMobilePhone->text());
    _custom.setFax(ui->leFax->text());

    qDebug() << _custom.getId();
    _custom.commit();
    QDialog::accept();
}

void DialogAddCustomer::reject() {
    QDialog::reject();
}

DialogAddCustomer::~DialogAddCustomer()
{
    // I change the information of customer id{
    delete ui;
}

