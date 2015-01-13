#include "userdatadialog.h"
#include "ui_userdatadialog.h"

userdatadialog::userdatadialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userdatadialog)
{
    ui->setupUi(this);
}

userdatadialog::~userdatadialog()
{
    delete ui;
}
