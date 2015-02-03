#include "addquotedialog.h"
#include "ui_addquotedialog.h"
#include "widgets/contributorieswidget.h"

AddQuoteDialog::AddQuoteDialog(int idCustomer, int id, QWidget *parent) :
    QDialog(parent),
    _quote(0),
    ui(new Ui::AddQuoteDialog)
{
    ui->setupUi(this);
    if (id != 0) {
        // WARNING : Possibility to update a quote ?

        //_quote = new Billing(id);
        //fillFields();
        //setWindowTitle("Modifier le client "+_custom->getCompany());
    } else {
        _quote = new Billing();
        ui->dateEditQuote->setDate(QDate::currentDate());
    }
    _quote->setId(id);
    _quote->setIsBilling(false);
    ui->wdgContributories = new ContributoriesWidget(new Customer(idCustomer), this);
    ui->_2->addWidget(ui->wdgContributories, 5, 0, 1, 2);
    connect(ui->wdgContributories, SIGNAL(contributoryChanged()), this, SLOT(updateBtn()));
}

AddQuoteDialog::~AddQuoteDialog()
{
    delete _quote;
    delete ui;
}

void AddQuoteDialog::fillFields() {
    // WARNING : Possibility to update a quote ?
    ui->leQuoteTitle->setText(_quote->getTitle());
}

void AddQuoteDialog::accept() {
    _quote->setTitle(ui->leQuoteTitle->text());
    _quote->setDescription(ui->leDescription->toPlainText());
    _quote->setDate(ui->dateEditQuote->date());

    for(Contributory c : ((ContributoriesWidget*)ui->wdgContributories)->getContributories()) {
        _quote->addContributory(c);
    }
    //_quote->setContributories(->getContributories());
    _quote->commit();
    QDialog::accept();
}

void AddQuoteDialog::reject() {
    QDialog::reject();
}

void AddQuoteDialog::updateBtn()
{
    ui->btnSave->setEnabled(((ContributoriesWidget*)ui->wdgContributories)->count() > 0);
}
