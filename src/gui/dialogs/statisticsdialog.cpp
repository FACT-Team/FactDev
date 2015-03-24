#include "statisticsdialog.h"
#include "ui_statisticsdialog.h"

#include "database/billingdatabase.h"

using namespace Databases;

namespace Gui {
namespace Dialogs {

StatisticsDialog::StatisticsDialog(bool global, int idCustomer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatisticsDialog)
{
    ui->setupUi(this);
    //setWindowTitle("Statistiques");

    int nbBills, nbBillsPaid, nbQuotes, turnover;

    if (global) {
        ui->lblTitle->setText("Statistiques globales");
        nbBills = BillingDatabase::instance()->getNbBills();
        nbBillsPaid = BillingDatabase::instance()->getNbBillsPaid();
        nbQuotes = BillingDatabase::instance()->getNBQuotes();
    } else {
        ui->lblTitle->setText("Statistiques du client");
        nbBills = BillingDatabase::instance()->getNbBills();
        nbBillsPaid = BillingDatabase::instance()->getNbBillsPaid();
        nbQuotes = BillingDatabase::instance()->getNBQuotes();
    }

    QString txt = QString::number(nbBills);
    if (nbBills == 0 || nbBills == 1) {
        txt += " facture dont " + QString::number(nbBillsPaid);
    } else if (nbBills > 1) {
        txt += " factures dont " + QString::number(nbBillsPaid);
    }
    if (nbBillsPaid == 0 || nbBillsPaid == 1) {
        txt += " payée.";
    } else if (nbBillsPaid > 1) {
        txt = " payées.";
    }
    ui->lblBills->setText(txt);
}

StatisticsDialog::~StatisticsDialog()
{
    delete ui;
}

}
}
