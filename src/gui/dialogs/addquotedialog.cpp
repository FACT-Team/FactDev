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

    if (id != 0) {
        _quote = new Billing(id);
        fillFields();
        if (isBilling) setWindowTitle("Modifier la facture n°"
                                      + QString::number(getNumber()) + " de "
                                      + (Customer(idCustomer).getCompany()));
        else setWindowTitle("Modifier le devis n°"
                            + QString::number(getNumber()) + " de "
                            + (Customer(idCustomer).getCompany()));
    } else {
        _quote = new Billing();
        _quote->setId(id);
        ui->dateEditQuote->setDate(QDate::currentDate());
        if (isBilling) setWindowTitle("Nouveau devis n°"
                                      +  QString::number(getNumber()) + " de "
                                      + (Customer(idCustomer).getCompany()));
        else setWindowTitle("Nouvelle facture n°"
                            +  QString::number(getNumber()) + " de "
                            + (Customer(idCustomer).getCompany()));
    }
    _quote->setIsBilling(isBilling);
    ui->_2->addWidget(ui->wdgContributories, 5, 0, 1, 2);
    connect(ui->wdgContributories, SIGNAL(contributoryChanged()), this, SLOT(updateBtn()));
    emit ui->leQuoteTitle->textChanged(_quote->getTitle());
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

    ((Gui::Widgets::ContributoriesWidget*)ui->wdgContributories)->add(_quote->getContributories().getAllContributories());
}

void AddQuoteDialog::accept() {
    _quote->setTitle(ui->leQuoteTitle->text());
    _quote->setDescription(ui->leDescription->toPlainText());
    _quote->setDate(ui->dateEditQuote->date());

    for(Contributory c : ((Gui::Widgets::ContributoriesWidget*)ui->wdgContributories)->getContributories()) {
        _quote->addContributory(c);
    }
    _quote->commit();
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
