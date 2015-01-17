#include "dialogs/addprojectdialog.h"
#include "ui_addprojectdialog.h"
#include "database/customerdatabase.h"

AddProjectDialog::AddProjectDialog(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProjectDialog)
{

    _project = Project(id);
    ui->setupUi(this);



}

AddProjectDialog::~AddProjectDialog()
{
    delete ui;
}

void AddProjectDialog::accept()
{

    _project.setName(ui->leNameProject->text());
    _project.setDescription(ui->leDescription->toPlainText());
    _project.setDailyRate(ui->widget->getDailyRate());
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
