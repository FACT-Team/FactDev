#include "statisticsdialog.h"
#include "ui_statisticsdialog.h"

namespace Gui {
namespace Dialogs {

StatisticsDialog::StatisticsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatisticsDialog)
{
    ui->setupUi(this);
}

StatisticsDialog::~StatisticsDialog()
{
    delete ui;
}

}
}
