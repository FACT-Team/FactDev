#include <QFileDialog>
#include "userdatadialog.h"
#include "ui_userdatadialog.h"

namespace Gui {
namespace Dialogs {

UserDataDialog::UserDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDataDialog)
{
    ui->setupUi(this);
    _user = new User(1);
    ui->tabUserData->setCurrentIndex(0);
    fillFields();
    emit checkFields();
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
    ui->leNoSiret->setText(_user->getNoSiret());
    ui->leWorkspaceName->setText(_user->getWorkspaceName());
    ui->leWorkspacePath->setText(_user->getWorkspacePath());
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
    _user->setNoSiret(ui->leNoSiret->text());

    if (ui->leWorkspaceName->text().isEmpty()) {
        _user->setWorkspaceName("FactDev");
    } else {
        _user->setWorkspaceName(ui->leWorkspaceName->text());
    }

    if (ui->leWorkspacePath->text().isEmpty()) {
        _user->setWorkspacePath(QCoreApplication::applicationDirPath());
    } else {
        _user->setWorkspacePath(ui->leWorkspacePath->text());
    }

    _user->commit();
    QDialog::accept();
}

void UserDataDialog::reject()
{
    QDialog::reject();
}

void UserDataDialog::checkFields() {
    ui->lePostalCode->setCountry("FRANCE");
    ui->lePhone->setCountry("FRANCE");
    ui->leMobilePhone->setCountry("FRANCE");
    ui->btnValid->setEnabled(
        ui->leFirstname->isValid() && ui->leLastname->isValid()
        && ui->leCompany->isValid() && ui->leTitle->isValid()
        && ui->leAddress->isValid() && ui->leCity->isValid()
        && ui->lePostalCode->isValid() && ui->leEmail->isValid()
        && ((ui->lePhone->isValid() && ui->leMobilePhone->isValid())
            || (ui->lePhone->text().isEmpty() && ui->leMobilePhone->isValid())
            || (ui->lePhone->isValid() && ui->leMobilePhone->text().isEmpty()) )
                && ui->leNoSiret->isValid());
}

void UserDataDialog::browseWorkspacePath()
{
    QDir path;
    QFileDialog fileWindow( this,
                            "Espace de travail",
                            ui->leWorkspaceName->text(),
                            "*");
    fileWindow.exec();
    path = fileWindow.directory();

    ui->leWorkspacePath->setText(path.absolutePath());
}

}
}
