#include "statisticsdialog.h"
#include "ui_statisticsdialog.h"

namespace Gui {
namespace Dialogs {

StatisticsDialog::StatisticsDialog(bool global, int idCustomer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatisticsDialog)
{
    ui->setupUi(this);
    if (global) {
        ui->lblTitle->setText("Statistiques globales");
    } else {
        ui->lblTitle->setText("Statistiques du client ");
    }
}

StatisticsDialog::~StatisticsDialog()
{
    delete ui;
}

}
}
