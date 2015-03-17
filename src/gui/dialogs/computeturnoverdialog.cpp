#include "computeturnoverdialog.h"
#include "ui_computeturnoverdialog.h"


namespace Gui {
namespace Dialogs {
ComputeTurnoverDialog::ComputeTurnoverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputeTurnoverDialog)
{
    ui->setupUi(this);
}

ComputeTurnoverDialog::~ComputeTurnoverDialog()
{
    delete ui;
}

void ComputeTurnoverDialog::fillLabels(const int nbBillings, const int turnover)
{
    ui->lbCompute->setText("Votre CA du "+
                           ui->dtBeginPeriod->date().toString("dd/MM/yyyy") +
                           " au " +
                           ui->dtEndPeriod->date().toString("dd/MM/yyyy") +
                           " est de " +
                           QString::number(turnover) + " euro(s)");
    ui->lbBillingNb->setText(QString::number(nbBillings) +
                             " Facture(s) trouvée(s)");
}

void ComputeTurnoverDialog::computeTurnover()
{
    QList<Project*> projects;
    QList<Billing> bills;
    double turnover = 0;
    int nbBillings = 0;

    projects = Databases::ProjectDatabase::instance()->getAllProjects();

     for (Project *p : projects) {
         bills = Databases::BillingDatabase::instance()
                 ->getAllBillingsOnly(p->getId());
        for (Billing b  : Databases::BillingDatabase::instance()
             ->getBillingsBetweenDates(bills,
                                     ui->dtBeginPeriod->date(),
                                     ui->dtEndPeriod->date())) {
            ContributoriesList cl = Databases::ContributoryDatabase::instance()
                    ->getContributoriesByBillingAndProject(b.getId(),
                                                         p->getId());
            Rate rate = Databases::RateDatabase::instance()->getRate(b.getId(),
                                                                   p->getId());
            turnover += (cl.getSumQuantity()) * rate.getHourlyRate();
            ++nbBillings;
         }
     }
    fillLabels(nbBillings,turnover);
}

void ComputeTurnoverDialog::endDateControl(const QDate end)
{
    if (end < ui->dtBeginPeriod->date()) {
        ui->dtBeginPeriod->setDate(ui->dtEndPeriod->date());
    }
}

void ComputeTurnoverDialog::beginDateControl(const QDate begin)
{
    if (begin > ui->dtEndPeriod->date()) {
        ui->dtEndPeriod->setDate(ui->dtBeginPeriod->date());
    }
}
}
}
