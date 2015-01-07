#include "dialogs/dialogaddcustomer.h"
#include "ui_dialogaddcustomer.h"

DialogAddClient::DialogAddClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddClient)
{
    ui->setupUi(this);
}

DialogAddClient::~DialogAddClient()
{
    delete ui;
}
