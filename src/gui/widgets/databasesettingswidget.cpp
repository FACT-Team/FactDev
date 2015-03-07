#include "databasesettingswidget.h"
#include "ui_databasesettingswidget.h"

namespace Gui {
namespace Widgets {


DatabaseSettingsWidget::DatabaseSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatabaseSettingsWidget)
{
    ui->setupUi(this);
}

DatabaseSettingsWidget::~DatabaseSettingsWidget()
{
    delete ui;
}

bool DatabaseSettingsWidget::isValid()
{
    return  ui->leDbName->isValid()
            && ui->leUser->isValid()
            && (ui->leLogin->isValid() && ui->leLoginRepeat->isValid())
            && ui->leIpAddress->isValid()
            && ui->lePort->isValid()
            ;
}

}
}
