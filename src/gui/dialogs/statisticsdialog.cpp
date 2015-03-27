#include "statisticsdialog.h"
#include "ui_statisticsdialog.h"

#include "database/billingdatabase.h"
#include "models/statistics.h"

using namespace Databases;

namespace Gui {
namespace Dialogs {

StatisticsDialog::StatisticsDialog(bool global, int customerId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatisticsDialog)
{
    ui->setupUi(this);

    int nbBills(    BillingDatabase::instance()->getNbBills(customerId));
    int nbBillsPaid(BillingDatabase::instance()->getNbBillsPaid(customerId));
    int nbQuotes(   BillingDatabase::instance()->getNbQuotes(customerId));
    int nbProjects( ProjectDatabase::instance()->getNbProjects(customerId));
    double turnover;

    if (global) {
        ui->lblTitle->setText("Statistiques globales");
        turnover = Models::Statistics::getGlobalTurnover();
    } else {
        Customer c(customerId);
        ui->lblTitle->setText("Statistiques du client " + c.getCompany());
        turnover = c.getTurnover();
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
        txt += " payées.";
    }
    ui->lblBills->setText(txt);
    ui->lblQuotes->setText(QString::number(nbQuotes) + " devis.");

    txt = QString::number(nbProjects);
    if (nbProjects == 0 || nbProjects == 1) {
        txt += " projet.";
    } else if (nbProjects > 1) {
        txt += " projets.";
    }
    ui->lblProject->setText(txt);
    ui->lblTurnover->setText(QString::number(turnover, 'f', 2) + " € de chiffre d'affaire généré.");
}

StatisticsDialog::~StatisticsDialog()
{
    delete ui;
}

}
}
