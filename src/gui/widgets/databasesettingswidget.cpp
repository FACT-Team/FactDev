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
    ui->leLogin->setText("FactDev");
    ui->leIpAddress->setText("127.0.0.1");
    ui->lePort->setText("3306");

    emit ui->leDbName->fieldTextChanged(ui->leDbName->text());
    emit ui->leLogin->fieldTextChanged(ui->leUser->text());
    emit ui->leIpAddress->fieldTextChanged(ui->leIpAddress->text());
    emit ui->lePort->fieldTextChanged(ui->lePort->text());
    emit isValid();
}

QString DatabaseSettingsWidget::getDatabaseName()
{
    return ui->leDbName->text();
}

QString DatabaseSettingsWidget::getLogin()
{
    return ui->leLogin->text();
}

QString DatabaseSettingsWidget::getPassword()
{
    return ui->lePassword->text();
}

QString DatabaseSettingsWidget::getDomainNameOrIP()
{
    return ui->leIpAddress->text();
}

QString DatabaseSettingsWidget::getPort()
{
    if (ui->lePort->text().isEmpty()) {
        return "3306";
    }
    return ui->lePort->text();
}

void DatabaseSettingsWidget::userInterfaceChanged()
{
    emit textfieldChanged();
}

bool DatabaseSettingsWidget::isValid()
{
   return  ui->leDbName->isValid()
            && ui->leLogin->isValid()
            && (ui->lePassword->isValid() && ui->lePasswordRepeat->isValid())
            && ui->leIpAddress->isValid()
            && ui->lePort->isValid()
            ;
}

void DatabaseSettingsWidget::checkRepeatPassword(QString text)
{
    ui->lePasswordRepeat->loginPreviousInputed(ui->leLogin->text());
    emit ui->leLoginRepeat->fieldTextChanged(text);
    emit isValid();
}

}
}
