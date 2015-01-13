#include "dialogs/dialogaddcustomer.h"
#include <QDebug>
#include "ui_dialogaddcustomer.h"

DialogAddCustomer::DialogAddCustomer(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddCustomer)
{
    ui->setupUi(this);
    if(id == 0) {
        // i'm a new customer o//
    } else {
        // I change the information of customer id
    }
}

void DialogAddCustomer::accept() {
    QDialog::accept();
    // if it's a new client
    // else it's an edition

}

void DialogAddCustomer::reject() {
    QDialog::reject();
}

DialogAddCustomer::~DialogAddCustomer()
{
    delete ui;
}
