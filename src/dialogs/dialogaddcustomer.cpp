#include "dialogs/dialogaddcustomer.h"
#include "ui_dialogaddcustomer.h"

DialogAddCustomer::DialogAddCustomer(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddCustomer),
    _custom(0)
{
    ui->setupUi(this);
    if (id != 0) {
        _custom = new Customer(id);
        fillFields();
        setWindowTitle("Modifier le client "+_custom->getCompany());
    } else {
        _custom = new Customer();
    }
    _custom->setId(id);
    emit checkFields();
}

void DialogAddCustomer::fillFields() {
    ui->leLastNameReferent->setText(_custom->getLastnameReferent());
    ui->leFirstNameReferent->setText(_custom->getFirstnameReferent());
    ui->leCompany->setText(_custom->getCompany());
    ui->leAddress->setText(_custom->getAddress());
    ui->leCity->setText(_custom->getCity());
    ui->lePostalCode->setText(_custom->getPostalCode());
    ui->leCountry->setText(_custom->getCountry());
    ui->leEmail->setText(_custom->getEmail());
    ui->lePhone->setText(_custom->getPhone());
    ui->leMobilePhone->setText(_custom->getMobilePhone());
    ui->leFax->setText(_custom->getFax());
}

void DialogAddCustomer::accept() {

    _custom->setLastnameReferent(ui->leLastNameReferent->text());
    _custom->setFirstnameReferent(ui->leFirstNameReferent->text());
    _custom->setCompany(ui->leCompany->text());
    _custom->setAddress(ui->leAddress->text());
    _custom->setCity(ui->leCity->text());
    _custom->setPostalCode(ui->lePostalCode->text());
    _custom->setCountry(ui->leCountry->text());
    _custom->setEmail(ui->leEmail->text());
    _custom->setPhone(ui->lePhone->text());
    _custom->setMobilePhone(ui->leMobilePhone->text());
    _custom->setFax(ui->leFax->text());

    _custom->commit();
    QDialog::accept();
}

void DialogAddCustomer::reject() {
    QDialog::reject();
}

DialogAddCustomer::~DialogAddCustomer()
{
    delete _custom;
    delete ui;
}

void DialogAddCustomer::checkFields() {
    ui->btnSave->setEnabled(
        ui->leFirstNameReferent->isValid() && ui->leLastNameReferent->isValid()
        && ui->leCompany->isValid()
        && ui->leAddress->isValid() && ui->leCity->isValid()
        && ui->lePostalCode->isValid() && ui->leCountry->isValid()
        && ui->leEmail->isValid()
        && ((ui->lePhone->isValid() && ui->leMobilePhone->isValid())
            || (ui->lePhone->text() == "" && ui->leMobilePhone->isValid())
            || (ui->lePhone->isValid() && ui->leMobilePhone->text() == "" ))
//        && ui->leFax->isValid()
        );
}

