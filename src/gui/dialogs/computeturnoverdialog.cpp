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

void ComputeTurnoverDialog::computeTurnover()
{
    QList<Project*> projects;
    QList<Billing> bills;
    QList<Contributory *> contributories;
    double turnover = 0;

    projects = Databases::ProjectDatabase::instance()->getAllProjects();


     for (Project *p : projects) {
         bills = Databases::BillingDatabase::instance()->getAllBillingsOnly(p->getId());
        for (Billing b  : Databases::BillingDatabase::instance()->getBillingsBetweenDates(bills,ui->dtBeginPeriod->date(),ui->dtEndPeriod->date())) {
            Models::ContributoriesList cl = Databases::ContributoryDatabase::instance()->getContributoriesByBillingAndProject(b.getId(), p->getId());
            Rate rate = Databases::RateDatabase::instance()->getRate(b.getId(), p->getId());
            turnover += (cl.getSumQuantity()) * rate.getHourlyRate();
         }
     }


    ui->lbCompute->setAlignment(Qt::AlignCenter);
    ui->lbCompute->setText("Votre CA du "+ui->dtBeginPeriod->date().toString("dd/MM/yyyy") +
                           " au " + ui->dtEndPeriod->date().toString("dd/MM/yyyy") +
                           " est de " + QString::number(turnover));

}

void ComputeTurnoverDialog::endDateControl(QDate end)
{
    if (end < ui->dtBeginPeriod->date()) {
        ui->dtBeginPeriod->setDate(ui->dtEndPeriod->date());
    }
}

void ComputeTurnoverDialog::beginDateControl(QDate begin)
{
    if (begin > ui->dtEndPeriod->date()) {
        ui->dtEndPeriod->setDate(ui->dtBeginPeriod->date());
    }
}
}
}
