#include "databasesettingswidget.h"
#include "ui_databasesettingswidget.h"

namespace Gui {
namespace Widgets {


DatabaseSettingsWidget::DatabaseSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatabaseSettingsWidget)
{
    ui->setupUi(this);
    fillFields();
}

DatabaseSettingsWidget::~DatabaseSettingsWidget()
{
    delete ui;
}

void DatabaseSettingsWidget::fillFields()
{
    ui->leDbName->setText("FactDev");
    ui->leUser->setText("FactDev");
    ui->leIpAddress->setText("127.0.0.1");
    ui->lePort->setText("3306");

    emit ui->leDbName->fieldTextChanged(ui->leDbName->text());
    emit ui->leUser->fieldTextChanged(ui->leUser->text());
    emit ui->leIpAddress->fieldTextChanged(ui->leIpAddress->text());
    emit ui->lePort->fieldTextChanged(ui->lePort->text());
    emit isValid();
}

void DatabaseSettingsWidget::userInterfaceChanged()
{
    emit textfieldChanged();
}

bool DatabaseSettingsWidget::isValid()
{    
    return  ui->leDbName->isValid()
            && ui->leUser->isValid()
            && (ui->leLogin->isValid() && ui->leLoginRepeat->isValid())
            && ui->leIpAddress->isValid()
            ;
}

void DatabaseSettingsWidget::checkRepeatLogin(QString text)
{
    ui->leLoginRepeat->loginPreviousInputed(ui->leLogin->text());
    emit ui->leLoginRepeat->fieldTextChanged(text);
    emit isValid();
}

}
}
