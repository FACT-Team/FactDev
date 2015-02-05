#include "ratewidget.h"
#include "ui_ratewidget.h"


RateWidget::RateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RateWidget)
{
    ui->setupUi(this);
    _isDailyRateModified = false;
    initRate();
}

RateWidget::~RateWidget()
{
    delete ui;
}

void RateWidget::initRate() {
    ui->sbDailyRate->setValue(Project::NB_DAILY_HOURS * Project::LEGAL_RATE);
    ui->sbHourlyRate->setValue(Project::LEGAL_RATE);
}

void RateWidget::setWidgetDailyRateValue(double value)
{
    ui->sbDailyRate->setValue(value);
    emit setDailyRate();
}

double RateWidget::getDailyRate() {
    return ui->sbDailyRate->value();
}

void RateWidget::setDailyRate() {

    if (ui->sbDailyRate->value() > Project::NB_DAILY_HOURS * Project::LEGAL_RATE) {
        _isDailyRateModified = true;        
        updateConversionRate();
    } else {
       initRate();
    }

}

double RateWidget::getHourlyRate() {
    return ui->sbHourlyRate->value();
}

void RateWidget::setHourlyRate() {
    if (ui->sbHourlyRate->value() > Project::LEGAL_RATE) {
        _isDailyRateModified = false;
        updateConversionRate();
    } else {
        initRate();
    }
}

void RateWidget::updateConversionRate() {
    if (_isDailyRateModified) {
        ui->sbHourlyRate->setValue(getDailyRate()/Project::NB_DAILY_HOURS);
    } else {
        ui->sbDailyRate->setValue(getHourlyRate()*Project::NB_DAILY_HOURS);
    }
}


