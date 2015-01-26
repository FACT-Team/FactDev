#include "dialogs/addprojectdialog.h"
#include "ui_addprojectdialog.h"
#include "database/customerdatabase.h"

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

AddProjectDialog::~AddProjectDialog()
{
    delete ui;
}

void AddProjectDialog::accept() {

    _project.setName(ui->leNameProject->text());
    _project.setDescription(ui->leDescription->toPlainText());
    _project.setDailyRate(ui->widget->getDailyRate());
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

void AddProjectDialog::checkFields()
{
    ui->btnValid->setEnabled(ui->leNameProject->isValid()
                            && ui->wdgSearch->isCustomerSelected());
}
