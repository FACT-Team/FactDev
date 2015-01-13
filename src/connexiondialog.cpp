#include "connexiondialog.h"
#include "ui_connexiondialog.h"

connexiondialog::connexiondialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connexiondialog)
{
    ui->setupUi(this);
}

connexiondialog::~connexiondialog()
{
    delete ui;
}
