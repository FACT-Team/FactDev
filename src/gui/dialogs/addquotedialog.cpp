#include "addquotedialog.h"

#include "ui_addquotedialog.h"
namespace Gui {
namespace Dialogs {

AddQuoteDialog::AddQuoteDialog(bool isBilling, int idCustomer, int id, bool copy, QWidget *parent) :
    QDialog(parent),
    _quote(0),
    ui(new Ui::AddQuoteDialog),
    _copy(copy),
    _idCustomer(idCustomer)
{
    ui->setupUi(this);
    ui->wdgContributories = new Gui::Widgets::ContributoriesWidget(QSharedPointer<Customer>(new Customer(idCustomer)), this);
    connect(ui->wdgContributories, SIGNAL(contributoryChanged()), this, SLOT(updateBtn()));

    if (id != 0) {
        _quote = new Billing(id);
        fillFields();
        if (copy) {
            _quote->setId(0);
            _quote->setNumber(isBilling ? Databases::BillingDatabase::instance()->getMaxBillingNumberOfCustomer(idCustomer)+1
                                        : Databases::BillingDatabase::instance()->getMaxQuoteNumberOfCustomer(idCustomer)+1);

            setWindowTitle((isBilling ? "Nouvelle facture " : "Nouveau devis ")+
                           QString::number(getNumber())+ " de " +
                           (Customer(idCustomer).getCompany()));
            ui->btnDocChange->setText(isBilling ? "Changer en devis" : "Changer en facture");
        }
        else {
            ui->btnDocChange->hide();
            setWindowTitle((isBilling ? "Modifier la facture " : "Modifier le devis ")+
                           QString::number(getNumber())+ " de " +
                           (Customer(idCustomer).getCompany()));
        }
    } else {
        _quote = new Billing();
        _quote->setId(id);
        _quote->setNumber(isBilling ? Databases::BillingDatabase::instance()->getMaxBillingNumberOfCustomer(idCustomer)+1
                                    : Databases::BillingDatabase::instance()->getMaxQuoteNumberOfCustomer(idCustomer)+1);

        ui->dateEditQuote->setDate(QDate::currentDate());
        ui->btnDocChange->hide();

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
    if(_copy) {
        _quote->getContributories().setAllIdContributories(0);
        if(_quote->isBilling() && _quote->isPaid()) {
            _quote->setIsPaid(false);
        }
    }

    _quote->commit();
    _quote->generateTex();
    QDialog::accept();
}

void AddQuoteDialog::reject() {
    QDialog::reject();
}

bool AddQuoteDialog::getCopy() const
{
    return _copy;
}

void AddQuoteDialog::setCopy(bool copy)
{
    _copy = copy;
}

void AddQuoteDialog::updateBtn() {
    ui->btnSave->setEnabled(
                ((Gui::Widgets::ContributoriesWidget*)ui->wdgContributories)->count() > 0
                && ui->leQuoteTitle->isValid());
}

void AddQuoteDialog::changeDocType()
{
    _quote->setIsBilling(!_quote->isBilling());
    _quote->setNumber(_quote->isBilling() ? Databases::BillingDatabase::instance()->getMaxBillingNumberOfCustomer(_idCustomer)+1
                                : Databases::BillingDatabase::instance()->getMaxQuoteNumberOfCustomer(_idCustomer)+1);

    if (_quote->isBilling()) {
        setWindowTitle("Nouvelle facture " +
                       QString::number(_quote->getNumber())+ " de " +
                       Customer(_idCustomer).getCompany());
    } else {
        setWindowTitle("Nouveau devis " +
                       QString::number(_quote->getNumber())+ " de "+
                       Customer(_idCustomer).getCompany());
    }

}
}
}
