#include "addprojectdialog.h"
#include "ui_addprojectdialog.h"

AddProjectDialog::AddProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProjectDialog)
{
    ui->setupUi(this);
}

AddProjectDialog::~AddProjectDialog()
{
    delete ui;
}
