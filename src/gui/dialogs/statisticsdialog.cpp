#include "statisticsdialog.h"
#include "ui_statisticsdialog.h"

#include "database/billingdatabase.h"
#include "models/statistics.h"

using namespace Databases;

namespace Gui {
namespace Dialogs {

StatisticsDialog::StatisticsDialog(bool isGlobal, int customerId, QWidget *parent) :
    isGlobal(isGlobal),
    customerId(customerId),
    QDialog(parent),
    ui(new Ui::StatisticsDialog)
{
    ui->setupUi(this);

    int nbBills(    BillingDatabase::instance()->getNbBills(customerId));
    int nbBillsPaid(BillingDatabase::instance()->getNbBillsPaid(customerId));
    int nbQuotes(   BillingDatabase::instance()->getNbQuotes(customerId));
    int nbProjects( ProjectDatabase::instance()->getNbProjects(customerId));

    updateUi(nbBills, nbBillsPaid, nbQuotes, nbProjects);
}

void StatisticsDialog::updateUi(int nbBills, int nbBillsPaid, int nbQuotes, int nbProjects) {
    changeMainTitle();

    QString txt = QString::number(nbBills) + " facture"
            + singularPlural(nbBills) + " dont " + QString::number(nbBillsPaid)
            + " payée" + singularPlural(nbBillsPaid) + ".";

    ui->lblBills->setText(txt);
    ui->lblQuotes->setText(QString::number(nbQuotes) + " devis.");

    txt = QString::number(nbProjects) + " projet"
            + singularPlural(nbProjects) + ".";

    ui->lblProject->setText(txt);

    double turnover;
    if (isGlobal) {
        turnover = Models::Statistics::getGlobalTurnover();
    } else {
        Customer c(customerId);
        turnover = c.getTurnover();
    }

    ui->lblTurnover->setText(QString::number(turnover, 'f', 2)
                             + " € de chiffre d'affaire généré.");
}

void StatisticsDialog::changeMainTitle() {
    if (isGlobal) {
        ui->lblTitle->setText("Statistiques globales");
    } else {
        Customer c(customerId);
        ui->lblTitle->setText("Statistiques du client " + c.getCompany());
    }
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
