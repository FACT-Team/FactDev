#include "gui/dialogs/dialogaddcustomer.h"
#include "ui_dialogaddcustomer.h"
#include "gui/utils/windowsettings.h"
#include <QDebug>

#include <QDebug>
namespace Gui {
namespace Dialogs {

DialogAddCustomer::DialogAddCustomer(int id, QWidget *parent) :
    QDialog(parent),
    _custom(0),
    ui(new Ui::DialogAddCustomer)
{
    ui->setupUi(this);
    Utils::WindowSettings::setPositionToCenter(*this);

    if (id != 0) {
        _custom = QSharedPointer<Models::Customer>(new Customer(id));
        fillFields();
        setWindowTitle("Modifier le client "+_custom->getCompany());
    } else {
        _custom = QSharedPointer<Models::Customer>(new Customer());
    }
    _custom->setId(id);
    _custom->setToRemoved(false);
    emit checkFields();
}

void DialogAddCustomer::fillFields() {
    ui->leLastNameReferent->setText(_custom->getLastname());
    ui->leFirstNameReferent->setText(_custom->getFirstname());
    ui->leCompany->setText(_custom->getCompany());
    ui->leAddress->setText(_custom->getAddress());
    ui->leCity->setText(_custom->getCity());
    ui->lePostalCode->setText(_custom->getPostalCode());
    ui->leCountry->setText(_custom->getCountry());
    ui->leEmail->setText(_custom->getEmail());
    ui->lePhone->setText(_custom->getPhone());
    ui->leMobilePhone->setText(_custom->getMobilePhone());
    ui->leFax->setText(_custom->getFax());

    if (!_custom->getImage()->isNull()) {
        ui->wgtLogo->setImage(_custom->getImage());
    }
    ui->leWebsite->setText(_custom->getWebsite());
    ui->leComplement->setText(_custom->getAddressComplement());
}

void DialogAddCustomer::accept() {
    _custom->setLastname(ui->leLastNameReferent->text());
    _custom->setFirstname(ui->leFirstNameReferent->text());
    _custom->setCompany(ui->leCompany->text());
    _custom->setAddress(ui->leAddress->text());
    _custom->setCity(ui->leCity->text());
    _custom->setPostalCode(ui->lePostalCode->text());
    _custom->setCountry(ui->leCountry->text());
    _custom->setEmail(ui->leEmail->text());
    _custom->setPhone(ui->lePhone->text());
    _custom->setMobilePhone(ui->leMobilePhone->text());
    _custom->setFax(ui->leFax->text());    
    _custom->setWebsite(ui->leWebsite->text());
    _custom->setAddressComplement(ui->leComplement->text());
    _custom->setIsArchived(false);

    _custom->commit();

    if (!ui->wgtLogo->getImage()->isNull()) {
        _custom->setExtensionImage(ui->wgtLogo->getExtension());
        _custom->setImage(ui->wgtLogo->getImage());
    }
    QDialog::accept();
}

void DialogAddCustomer::reject() {
    QDialog::reject();
}

DialogAddCustomer::~DialogAddCustomer()
{
    _custom.reset();
    delete ui;
}

void DialogAddCustomer::checkFields() {
    ui->lePostalCode->setCountry(ui->leCountry->text());
    ui->lePhone->setCountry(ui->leCountry->text());
    ui->leMobilePhone->setCountry(ui->leCountry->text());
    ui->leFax->setCountry(ui->leCountry->text());

    if (!ui->leMobilePhone->text().isEmpty()) {
        ui->leMobilePhone->fieldTextChanged(ui->leMobilePhone->text());
    }
    if (!ui->lePhone->text().isEmpty()) {
        ui->lePhone->fieldTextChanged(ui->lePhone->text());
    }
    if (!ui->leFax->text().isEmpty()) {
        ui->leFax->fieldTextChanged(ui->leFax->text());
    }
    if (!ui->lePostalCode->text().isEmpty()) {
        ui->lePostalCode->fieldTextChanged(ui->lePostalCode->text());
    }

    ui->btnSave->setEnabled(
        ui->leFirstNameReferent->isValid() && ui->leLastNameReferent->isValid()
        && ui->leCompany->isValid()
        && ui->leAddress->isValid() && ui->leCity->isValid()
        && ui->lePostalCode->isValid() && ui->leCountry->isValid()
        && ui->leEmail->isValid()
        && ((ui->lePhone->isValid() && ui->leMobilePhone->isValid())
            || (ui->lePhone->text().isEmpty() && ui->leMobilePhone->isValid())
            || (ui->lePhone->isValid() && ui->leMobilePhone->text().isEmpty()) )
        && (ui->leFax->text().isEmpty() || ui->leFax->isValid()) && ui->leWebsite->isValid()
        );
}

}
}
