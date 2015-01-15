#include "ratewidget.h"
#include "ui_ratewidget.h"

RateWidget::RateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RateWidget)
{
    ui->setupUi(this);
}

RateWidget::~RateWidget()
{
    delete ui;
}

double RateWidget::getDailyRate() {
    return ui->sbDaylyRate->value();
}

void RateWidget::setDailyRate(double dailyRate) {
    ui->sbDaylyRate->setValue(dailyRate);
}

double RateWidget::getHourlyRate() {
    ui->sbHourlyRate->value();
}

void RateWidget::setHourlyRate(double hourlyRate) {
    ui->sbHourlyRate->setValue(hourlyRate);
}


