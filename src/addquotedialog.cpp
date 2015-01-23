#include "addquotedialog.h"
#include "ui_addquotedialog.h"

AddQuoteDialog::AddQuoteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddQuoteDialog)
{
    ui->setupUi(this);
}

AddQuoteDialog::~AddQuoteDialog()
{
    delete ui;
}
