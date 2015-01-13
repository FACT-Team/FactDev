#include "userdialog.h"
#include "ui_userdialog.h"

userdialog::userdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userdialog)
{
    ui->setupUi(this);
}

userdialog::~userdialog()
{
    delete ui;
}
