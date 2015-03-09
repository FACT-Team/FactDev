#include "addquotedialog.h"

#include "ui_addquotedialog.h"
namespace Gui {
namespace Dialogs {

AddQuoteDialog::AddQuoteDialog(bool isBilling, int idCustomer, int id, QWidget *parent) :
    QDialog(parent),
    _quote(0),
    ui(new Ui::AddQuoteDialog)
{
    ui->setupUi(this);
    ui->wdgContributories = new Gui::Widgets::ContributoriesWidget(QSharedPointer<Customer>(new Customer(idCustomer)), this);
    connect(ui->wdgContributories, SIGNAL(contributoryChanged()), this, SLOT(updateBtn()));

    if (id != 0) {
        _quote = new Billing(id);
        fillFields();

        setWindowTitle((isBilling ? "Modifier la facture " : "Modifier le devis ")+
                       QString::number(getNumber())+ " de " +
                       (Customer(idCustomer).getCompany()));
    } else {
        _quote = new Billing();
        _quote->setId(id);
        ui->dateEditQuote->setDate(QDate::currentDate());

        setWindowTitle((isBilling ? "Nouvelle facture " : "Nouveau devis ")+
                       QString::number(getNumber())+ " de " +
                       (Customer(idCustomer).getCompany()));
    }
    _quote->setIsBilling(isBilling);

    ui->_2->addWidget(ui->wdgContributories, 5, 0, 1, 2);
    emit ui->leQuoteTitle->textChanged(_quote->getTitle());
    ((Gui::Widgets::ContributoriesWidget*)ui->wdgContributories)->updateUi();
}

AddQuoteDialog::~AddQuoteDialog()
{
    delete _quote;
    delete ui;
}

int AddQuoteDialog::getNumber() {
    return _quote->getNumber();
}

void AddQuoteDialog::fillFields() {
     ui->leQuoteTitle->setText(_quote->getTitle());
     ui->dateEditQuote->setDate(_quote->getDate());
     ui->leDescription->setText(_quote->getDescription());

    ((Gui::Widgets::ContributoriesWidget*)ui->wdgContributories)->add(_quote->getContributories());
}

void AddQuoteDialog::accept() {
    _quote->setTitle(ui->leQuoteTitle->text());
    _quote->setDescription(ui->leDescription->toPlainText());
    _quote->setDate(ui->dateEditQuote->date());

    _quote->setContributories(*((Widgets::ContributoriesWidget*)ui->wdgContributories)->getContributories());

    _quote->commit();
    _quote->generatePdf();

    QDialog::accept();
}

void AddQuoteDialog::reject() {
    QDialog::reject();
}

void AddQuoteDialog::updateBtn() {
    ui->btnSave->setEnabled(
                ((Gui::Widgets::ContributoriesWidget*)ui->wdgContributories)->count() > 0
                && ui->leQuoteTitle->isValid());
}
}
}
