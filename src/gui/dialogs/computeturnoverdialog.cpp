#include "computeturnoverdialog.h"
#include "ui_computeturnoverdialog.h"


namespace Gui {
namespace Dialogs {
ComputeTurnoverDialog::ComputeTurnoverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputeTurnoverDialog)
{
    ui->setupUi(this);
    ui->clBeginPeriod->setSelectedDate(QDate(QDate::currentDate().year(),1,1));
    ui->clEndPeriod->setSelectedDate(QDate::currentDate());
}

ComputeTurnoverDialog::~ComputeTurnoverDialog()
{
    delete ui;
}

void ComputeTurnoverDialog::fillLabels(const int nbBillings, const int turnover)
{
    ui->lbCompute->setText("Votre CA du "+
                           ui->clBeginPeriod->selectedDate().toString("dd/MM/yyyy") +
                           " au " +
                           ui->clEndPeriod->selectedDate().toString("dd/MM/yyyy") +
                           " est de " +
                           QString::number(turnover) + " euro(s)");
    ui->lbBillingNb->setText(QString::number(nbBillings) +
                             " Facture(s) trouvée(s)");
    ui->leTurnover->setText(QString::number(turnover));
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
                                     ui->clBeginPeriod->selectedDate(),
                                     ui->clEndPeriod->selectedDate())) {
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
    if (end < ui->clBeginPeriod->selectedDate()) {
        ui->clBeginPeriod->setSelectedDate(ui->clEndPeriod->selectedDate());
    }
}

void ComputeTurnoverDialog::beginDateControl(const QDate begin)
{
    if (begin > ui->clEndPeriod->selectedDate()) {
        ui->clEndPeriod->setSelectedDate(ui->clBeginPeriod->selectedDate());
    }
}
}
}
