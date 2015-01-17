#include <QDebug>
#include "mainwindow.h"
#include "userdatadialog.h"
#include "ui_userdatadialog.h"

// Commentaire de Cédric :
// Je pense que dans la bar de menu on peit créer
// un bouton pour modifier les données de l'utilisateur ...
UserDataDialog::UserDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDataDialog)
{
    ui->setupUi(this);
    _user = new User(1);
    fillFields();
}

UserDataDialog::~UserDataDialog()
{
    delete ui;
}

void UserDataDialog::fillFields() {
    ui->leFirstname->setText(_user->getFirstname());
    ui->leLastname->setText(_user->getLastname());
    ui->leCompany->setText(_user->getCompany());
    ui->leTitle->setText(_user->getTitle());
    ui->leAddress->setText(_user->getAddress());
    ui->leCity->setText(_user->getCity());
    ui->lePostalCode->setText(_user->getPostalCode());
    ui->leEmail->setText(_user->getEmail());
    ui->lePhone->setText(_user->getPhone());
    ui->leMobilePhone->setText(_user->getMobilePhone());
    ui->leNoSiret->setText(QString::number(_user->getNoSiret()));
}

void UserDataDialog::accept() {
    _user->setFirstname(ui->leFirstname->text());
    _user->setLastname(ui->leLastname->text());
    _user->setCompany(ui->leCompany->text());
    _user->setTitle(ui->leTitle->text());
    _user->setAddress(ui->leAddress->text());
    _user->setCity(ui->leCity->text());
    _user->setPostalCode(ui->lePostalCode->text());
    _user->setEmail(ui->leEmail->text());
    _user->setPhone(ui->lePhone->text());
    _user->setMobilePhone(ui->leMobilePhone->text());
    _user->setNoSiret(ui->leNoSiret->text().toInt());

    _user->commit();
    QDialog::accept();
}

void UserDataDialog::reject()
{
    QDialog::reject();
}
