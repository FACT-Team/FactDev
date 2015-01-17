#include "ratewidget.h"
#include "ui_ratewidget.h"

RateWidget::RateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RateWidget)
{
    ui->setupUi(this);
    initRate();
}

RateWidget::~RateWidget()
{
    delete ui;
}

void RateWidget::initRate()
{
    ui->sbDaylyRate->setValue(NB_DAILY_HOURS * LEGAL_RATE);
    ui->sbHourlyRate->setValue(LEGAL_RATE);
}

double RateWidget::getDailyRate() {
    return ui->sbDaylyRate->value();
}

void RateWidget::setDailyRate(double dailyRate) {
    ui->sbDaylyRate->setValue(dailyRate);    
}

double RateWidget::getHourlyRate() {
    return ui->sbHourlyRate->value();
}

void RateWidget::setHourlyRate(double hourlyRate) {
    ui->sbHourlyRate->setValue(hourlyRate);
    ui->sbDaylyRate->setValue(hourlyRate*NB_DAILY_HOURS);
}


