#include "startedwindowsdialog.h"
#include "ui_startedwindowsdialog.h"

namespace Gui {
namespace Dialogs {


StartedWindowsDialog::StartedWindowsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartedWindowsDialog)
{
    ui->setupUi(this);
    ui->wdgStack->setCurrentIndex(0);
    _user = new User(1);
    //ui->lbIcon->setPixmap(getImage(":/icons/FactDev"));
    checkFields();
}

StartedWindowsDialog::~StartedWindowsDialog()
{
    delete ui;
}

void StartedWindowsDialog::nextToPage2()
{
    ui->wdgStack->setCurrentIndex(1);    
    //ui->lbIcon->setPixmap(getImage(":/icons/img/database.png"));
}

void StartedWindowsDialog::nextToPage3()
{
    ui->wdgStack->setCurrentIndex(2);
    //ui->lbIcon->setPixmap(getImage(":/icons/customer"));
}

void StartedWindowsDialog::accept() {
    _user->setFirstname(ui->leFirstname->text());
    _user->setLastname(ui->leLastname->text());
    _user->setCompany(ui->leCompany->text());
    _user->setTitle(ui->leTitle->text());
    _user->setAddress(ui->leAddress->text());
    _user->setCity(ui->leCity->text());
    _user->setPostalCode(ui->lePostalCode->text());
    _user->setEmail(ui->leEmail->text());
    _user->setPhone(ui->lePhone->text());
    _user->setMobilePhone(ui->leMobile->text());
    _user->setNoSiret(ui->leNoSiret->text());

    _user->commit();
    QDialog::accept();
}

QPixmap getImage(QString path, int width, int height) {
    QPixmap img(path);
    img.scaled(width,height,Qt::KeepAspectRatio);

    return img;
}

void StartedWindowsDialog::checkFields() {
    ui->lePostalCode->setCountry("FRANCE");
    ui->lePhone->setCountry("FRANCE");
    ui->leMobile->setCountry("FRANCE");
    ui->btnValidate->setEnabled(
        ui->leFirstname->isValid() && ui->leLastname->isValid()
        && ui->leCompany->isValid() && ui->leTitle->isValid()
        && ui->leAddress->isValid() && ui->leCity->isValid()
        && ui->lePostalCode->isValid() && ui->leEmail->isValid()
        && ((ui->lePhone->isValid() && ui->leMobile->isValid())
            || (ui->lePhone->text().isEmpty() && ui->leMobile->isValid())
            || (ui->lePhone->isValid() && ui->leMobile->text().isEmpty()) )
                && ui->leNoSiret->isValid()
       );
}



}
}
