#include "addquotedialog.h"
#include "ui_addquotedialog.h"

AddQuoteDialog::AddQuoteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddQuoteDialog),
    _quote(0)
{
    ui->setupUi(this);
    _quote = new Billing(false);

}

AddQuoteDialog::~AddQuoteDialog()
{
    delete _quote;
    delete ui;
}

void AddQuoteDialog::fillFields() {
    /*ui->leLastNameReferent->setText(_custom->getLastnameReferent());
    ui->leFirstNameReferent->setText(_custom->getFirstnameReferent());
    ui->leCompany->setText(_custom->getCompany());
    ui->leAddress->setText(_custom->getAddress());
    ui->leCity->setText(_custom->getCity());
    ui->lePostalCode->setText(_custom->getPostalCode());
    ui->leCountry->setText(_custom->getCountry());
    ui->leEmail->setText(_custom->getEmail());
    ui->lePhone->setText(_custom->getPhone());
    ui->leMobilePhone->setText(_custom->getMobilePhone());
    ui->leFax->setText(_custom->getFax());*/
}

void AddQuoteDialog::accept() {

    /*_custom->setLastnameReferent(ui->leLastNameReferent->text());
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

    _custom->commit();*/
    QDialog::accept();
}

void AddQuoteDialog::reject() {
    QDialog::reject();
}
