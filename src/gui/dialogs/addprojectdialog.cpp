#include "gui/dialogs/addprojectdialog.h"
#include "ui_addprojectdialog.h"

namespace Gui {
namespace Dialogs {

AddProjectDialog::AddProjectDialog(int idProject, int noRowCustomer, QWidget *parent) :
    QDialog(parent), ui(new Ui::AddProjectDialog)
{
    ui->setupUi(this);

    if(noRowCustomer != 0) {
        ui->wdgSearch->selectCustomer(noRowCustomer);
    }
    ui->leNameProject->setFocus();
    if(idProject != 0) {
        _project = Project(idProject);
        ui->wdgSearch->setIdCustomer(_project.getCustomer()->getId());
        fillFields();
        setWindowTitle("Modifier le projet " + _project.getName());
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

    if(_project.getCustomer() == 0) {
        _project.setCustomer(QSharedPointer<Customer>(new Customer(ui->wdgSearch->getCurrentCustomerId())));
    }

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
    ui->wdgRate->setWidgetDailyRateValue(_project.getDailyRate());
    ui->wdgSearch->hide();
    setMaximumHeight(280);
    setMaximumWidth(550);

}

void AddProjectDialog::checkFields()
{
    ui->btnValid->setEnabled(ui->leNameProject->isValid()
                            && ui->wdgSearch->isCustomerSelected());
}
}
}
