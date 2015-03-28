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

    QString txt = QString::number(nbBills) + " facture"
            + singularPlural(nbBills) + " dont " + QString::number(nbBillsPaid)
            + " payée" + singularPlural(nbBillsPaid) + ".";

    ui->lblBills->setText(txt);
    ui->lblQuotes->setText(QString::number(nbQuotes) + " devis.");

    txt = QString::number(nbProjects) + " projet"
            + singularPlural(nbProjects) + ".";

    ui->lblProject->setText(txt);
    ui->lblTurnover->setText(QString::number(turnover, 'f', 2)
                             + " € de chiffre d'affaire généré.");
}

QString StatisticsDialog::singularPlural(int nb) {
    QString ret("");
    if (nb > 1) ret = "s";
    return ret;
}

StatisticsDialog::~StatisticsDialog()
{
    delete ui;
}

}
}
