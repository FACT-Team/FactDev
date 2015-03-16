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
    double turnover = 0;

    projects = Databases::ProjectDatabase::instance()
            ->getAllProjectsBetweenDates(
                ui->dtBeginPeriod->date(),ui->dtEndPeriod->date());

    turnover = Databases::ProjectDatabase::instance()->getCostProjects(projects);

    ui->lbCompute->setAlignment(Qt::AlignCenter);
    ui->lbCompute->setText("Votre CA du "+ui->dtBeginPeriod->date().toString("dd/MM/yyyy") +
                           " au " + ui->dtEndPeriod->date().toString("dd/MM/yyyy") +
                           " est de " + QString::number(turnover));

}
}
}
