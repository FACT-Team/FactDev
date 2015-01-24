#include "QDebug"
#include "addquotedialog.h"
#include "ui_addquotedialog.h"
#include "widgets/contributorieswidget.h"

AddQuoteDialog::AddQuoteDialog(int idCustomer, int id, QWidget *parent) :
    QDialog(parent),
    _quote(0),
    ui(new Ui::AddQuoteDialog)
{
    ui->setupUi(this);
    id = 1;     // WARNING
    if (id != 0) {
        _quote = new Billing(id);
        qDebug() << _quote->getTitle();
        fillFields();
        //setWindowTitle("Modifier le client "+_custom->getCompany());
    } else {
        _quote = new Billing();
    }
    _quote->setId(id);
    _quote->setIsBilling(false);

    ui->wdgContributories = new ContributoriesWidget(new Customer(idCustomer), this);
    ui->_2->addWidget(ui->wdgContributories, 5, 0, 1, 2);
}

AddQuoteDialog::~AddQuoteDialog()
{
    delete _quote;
    delete ui;
}

void AddQuoteDialog::fillFields() {
    ui->leQuoteTitle->setText(_quote->getTitle());
}

void AddQuoteDialog::accept() {
    _quote->setTitle(ui->leQuoteTitle->text());
    _quote->setTitle(ui->leDescription->toPlainText());

    // TODO Implements me !

    _quote->commit();
    QDialog::accept();
}

void AddQuoteDialog::reject() {
    QDialog::reject();
}
