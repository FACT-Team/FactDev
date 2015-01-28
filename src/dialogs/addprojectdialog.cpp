#include "dialogs/addprojectdialog.h"
#include "ui_addprojectdialog.h"
#include "database/customerdatabase.h"
#include "mainwindow.h"

AddProjectDialog::AddProjectDialog(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProjectDialog)
{
    ui->setupUi(this);

    if(id != 0) {
        _project = Project(id);
        setWindowTitle("Modifier le projet "+_project.getName());
    } else {
        _project = Project();
    }
    emit checkFields();
}

AddProjectDialog::AddProjectDialog(int idCustomer, int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProjectDialog)
{
    ui->setupUi(this);
    ui->wdgSearch->selectCustomer(idCustomer);
    ui->leNameProject->setFocus();
    if(id != 0) {
        _project = Project(id);
        fillFields();
        setWindowTitle("Modifier le projet "+_project.getName());
    } else {
        _project = Project();
    }
    emit checkFields();
}

AddProjectDialog::~AddProjectDialog()
{
    delete ui;
}

void AddProjectDialog::accept() {

    _project.setName(ui->leNameProject->text());
    _project.setDescription(ui->leDescription->toPlainText());
    _project.setDailyRate(ui->wdgRate->getDailyRate());
    _project.setBeginDate(QDate::currentDate());
    _project.setCustomer(
                CustomerDatabase::instance()->getCustomer(
                    ui->wdgSearch->getCurrentCustomerId()));

    _project.commit();

    QDialog::accept();
}

void AddProjectDialog::reject()
{
    QDialog::reject();
}

void AddProjectDialog::fillFields() {
    ui->leNameProject->setText(_project.getName());
    ui->leDescription->setText(_project.getDescription());
    //ui->wdgRate->setDailyRate(_project.getDailyRate());
    ui->wdgRate->setWidgetDailyRateValue(_project.getDailyRate());
    ui->wdgSearch->setEnabled(false);
    qDebug() << _project.getName() + " " + _project.getDescription();
//    _project.commit();
}

void AddProjectDialog::checkFields()
{
    ui->btnValid->setEnabled(ui->leNameProject->isValid()
                            && ui->wdgSearch->isCustomerSelected());
}
