#include "addcontributorydialog.h"
#include "ui_addcontributorydialog.h"

AddContributoryDialog::AddContributoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContributoryDialog)
{
    ui->setupUi(this);
}

AddContributoryDialog::~AddContributoryDialog()
{
    delete ui;
}
