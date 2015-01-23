#include "dialogs/addprojectdialog.h"
#include "ui_addprojectdialog.h"
#include "database/customerdatabase.h"

AddProjectDialog::AddProjectDialog(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProjectDialog)
{

    _project = Project(id);
    ui->setupUi(this);

    if(id != 0) {
        setWindowTitle("Modifier le projet "+_project.getName());
    }
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
    _project.setBeginDate(QDate::currentDate());

    //Ne renvoie pas le bon ID
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
