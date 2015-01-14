#include "mainwindow.h"
#include "userdatadialog.h"
#include "ui_userdatadialog.h"

UserDataDialog::UserDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDataDialog)
{
    ui->setupUi(this);
    _user.setId(1);
}

UserDataDialog::~UserDataDialog()
{
    delete ui;
}

void UserDataDialog::accept()
{
    MainWindow win;
    _user.setFirstname(ui->leFirstname->text());
    _user.setLastname(ui->leLastname->text());
    _user.setCompany(ui->leCompany->text());
    _user.setAddress(ui->leAddress->text());
    _user.setCity(ui->leCity->text());
    _user.setPostalCode(ui->lePostalCode->text());
    _user.setCountry(ui->leCountry->text());
    _user.setEmail(ui->leEmail->text());
    _user.setPhone(ui->lePhone->text());
    _user.setMobilePhone(ui->leMobilePhone->text());
    _user.setFax(ui->leFax->text());
    _user.setNoSiret(ui->leNoSiret->text());

    _user.commit();
    win.updateUserData();
    QDialog::accept();

}

void UserDataDialog::reject()
{
    QDialog::reject();
}
