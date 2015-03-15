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
    ui->lbIcon->setPixmap(getImage(":/icons/FactDev"));
    ui->wdgDbType->hide();

    checkFields();
}

StartedWindowsDialog::~StartedWindowsDialog()
{
    delete _user;
    delete ui;
}

void StartedWindowsDialog::nextToPage2()
{
    ui->wdgStack->setCurrentIndex(1);    
    ui->lbIcon->setPixmap(getImage(":/icons/img/database.png"));
}

void StartedWindowsDialog::nextToPage3()
{

    ui->wdgStack->setCurrentIndex(2);
    //ui->lbIcon->setPixmap(getImage(":/icons/customer"));
    ui->lbIcon->setPixmap(getImage(":/icons/img/company.png"));
}

void StartedWindowsDialog::databaseTypeChanged(const int index)
{
    if (ui->cbDbType->itemText(index) == "Centralisée") {
        ui->lbDescriptionDbType->setText(
            "<html><head/><body> "
            "<p align='justify'><span style='font-style:italic;'> "
            "Une base de données "
            "</span><span style='font-weight:600; font-style:italic;'> "
            "centralisée</span><span style='font-style:italic;'> est créer "
            "sur un serveur distant. <br/>Elle est accessible "
            "depuis n'importe quels postes. <br/> "
            " </span></p></body></html>"
            );
        ui->wdgDbType->show();

        if (isDatabaseTypeValid()) {
            ui->btnNextTo3->setEnabled(true);
        } else {
            ui->btnNextTo3->setEnabled(false);
        }

    } else {
        ui->lbDescriptionDbType->setText(
            "<html><head/><body> "
            "<p align='justify'><span style='font-style:italic;'> "
            "Une base de données "
            "</span><span style='font-weight:600; font-style:italic;'> "
            "locale</span><span style='font-style:italic;'> est créer "
            "uniquement sur votre ordinateur. <br/>Elle est accessible "
            "uniquement depuis ce poste. <br/>Si vous souhaitez pouvoir "
            "vous connecter depuis un autre ordinateur<br/>et accéder "
            "aux même données il est recommandé d'utiliser une base "
            "<br/>de données centralisée. </span></p></body></html>"
            );
        ui->wdgDbType->hide();
        ui->btnNextTo3->setEnabled(true);
    }
}

bool StartedWindowsDialog::isDatabaseTypeValid()
{
    return  (isDatabaseCentralized() && ui->wdgDbType->isValid())
            || ui->cbDbType->currentText() == "Locale";
}

bool StartedWindowsDialog::isDatabaseCentralized()
{
    return ui->cbDbType->currentIndex() == 1;
}

void StartedWindowsDialog::updateNextButton()
{
    ui->btnNextTo3->setEnabled(isDatabaseTypeValid());
}



void StartedWindowsDialog::accept() {
    Databases::AccessDatabase::_address = ui->wdgDbType->getDomainNameOrIP();
    Databases::AccessDatabase::_dbName = ui->wdgDbType->getDatabaseName();
    Databases::AccessDatabase::_userDb = ui->wdgDbType->getLogin();
    Databases::AccessDatabase::_exists = true;
    Databases::AccessDatabase::_port = ui->wdgDbType->getPort().toInt();
    Databases::AccessDatabase::_password = ui->wdgDbType->getPassword();
    Databases::AccessDatabase::commit();

    _user = new User(1);
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

QPixmap StartedWindowsDialog::getImage(QString path, int width, int height) {
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
        && isDatabaseTypeValid()
        );
}

void StartedWindowsDialog::backToPage2()
{
    nextToPage2();
}



}
}
