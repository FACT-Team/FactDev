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
    //setWindowTitle("Statistiques");

    int nbBills, nbBillsPaid, nbQuotes, nbProjects;
    double turnover;

    if (global) {
        ui->lblTitle->setText("Statistiques globales");
        nbBills = BillingDatabase::instance()->getNbBills();
        nbBillsPaid = BillingDatabase::instance()->getNbBillsPaid();
        nbQuotes = BillingDatabase::instance()->getNbQuotes();
        nbProjects = ProjectDatabase::instance()->getNbProjects();
        turnover = Models::Statistics::getGlobalTurnover();
    } else {
        Customer c(customerId);
        ui->lblTitle->setText("Statistiques du client " + c.getCompany());
        nbBills = BillingDatabase::instance()->getNbBills(customerId);
        nbBillsPaid = BillingDatabase::instance()->getNbBillsPaid(customerId);
        nbQuotes = BillingDatabase::instance()->getNbQuotes(customerId);
        nbProjects = ProjectDatabase::instance()->getNbProjects(customerId);
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
