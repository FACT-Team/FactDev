#include "userdatadialog.h"
#include "ui_userdatadialog.h"

UserDataDialog::UserDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDataDialog)
{
    ui->setupUi(this);
}

UserDataDialog::~UserDataDialog()
{
    delete ui;
}
