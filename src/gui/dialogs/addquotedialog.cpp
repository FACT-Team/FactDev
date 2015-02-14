#include "addquotedialog.h"
#include "ui_addquotedialog.h"

namespace Gui {
namespace Dialogs {

AddQuoteDialog::AddQuoteDialog(int idCustomer, int id, QWidget *parent) :
    QDialog(parent),
    _quote(0),
    ui(new Ui::AddQuoteDialog)
{
    ui->setupUi(this);
    ui->wdgContributories = new Gui::Widgets::ContributoriesWidget(QSharedPointer<Customer>(new Customer(idCustomer)), this);

    if (id != 0) {
        _quote = new Billing(id);
        fillFields();
        setWindowTitle("Modifier le devis N°" + QString::number(_quote->getNumber()) +
                       " de " + (Customer(idCustomer).getCompany()));
    } else {
        _quote = new Billing();
        ui->dateEditQuote->setDate(QDate::currentDate());
        setWindowTitle("Nouveau devis de " + (Customer(idCustomer).getCompany()));
    }
    _quote->setId(id);
    _quote->setIsBilling(false);

    ui->_2->addWidget(ui->wdgContributories, 5, 0, 1, 2);
    connect(ui->wdgContributories, SIGNAL(contributoryChanged()), this, SLOT(updateBtn()));
    emit ui->leQuoteTitle->textChanged(_quote->getTitle());
}

AddQuoteDialog::~AddQuoteDialog()
{
    delete _quote;
    delete ui;
}

void AddQuoteDialog::fillFields() {

     ((CheckUntilField*) ui->leQuoteTitle)->setText(_quote->getTitle());
     ui->dateEditQuote->setDate(_quote->getDate());
     ui->leDescription->setText(_quote->getDescription());

     for(Project* p : _quote->getContributories().keys()) {
         for(Contributory c : _quote->getContributories()[p]) {
             //c.setProject(p);
            ((Gui::Widgets::ContributoriesWidget*)ui->wdgContributories)->add(c);
         }
     }
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
