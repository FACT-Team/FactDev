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
    ui->sbDailyRate->setValue(NB_DAILY_HOURS * LEGAL_RATE);
    ui->sbHourlyRate->setValue(LEGAL_RATE);
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

    if (ui->sbDailyRate->value() > NB_DAILY_HOURS * LEGAL_RATE) {
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
    if (ui->sbHourlyRate->value() > LEGAL_RATE) {
        _isDailyRateModified = false;
        updateConversionRate();
    } else {
        initRate();
    }
}

void RateWidget::updateConversionRate() {
    if (_isDailyRateModified) {
        ui->sbHourlyRate->setValue(getDailyRate()/NB_DAILY_HOURS);
    } else {
        ui->sbDailyRate->setValue(getHourlyRate()*NB_DAILY_HOURS);
    }
}


