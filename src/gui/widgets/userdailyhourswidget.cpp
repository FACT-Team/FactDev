#include "userdailyhourswidget.h"
#include "ui_userdailyhourswidget.h"
namespace Gui {
namespace Widgets {
UserDailyHoursWidget::UserDailyHoursWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserDailyHoursWidget)
{
    ui->setupUi(this);
    setupUI();
}

UserDailyHoursWidget::~UserDailyHoursWidget() {
    delete ui;
}

void UserDailyHoursWidget::setupUI()
{
    _idQuantity = DAILY_HOURS;
    ui->sbDailyHours->setValue(7.00);
    ui->sbWeeklyDays->setValue(5.00);
    ui->sbWeeklyHours->setValue(35.0);
    ui->sbMonthlyDays->setValue(20.0);
}

void UserDailyHoursWidget::dailyHoursValueHasChanged(const double value) {
    _idQuantity = DAILY_HOURS;
    updateWorkQuantity(value);
}

void UserDailyHoursWidget::weeklyDaysValueHasChanged(const double value) {
    _idQuantity = WEEKLY_DAYS;
    updateWorkQuantity(value);
}

void UserDailyHoursWidget::monthlyDaysValueHasChanged(const double value) {
    _idQuantity = MONTHLY_DAYS;
    updateWorkQuantity(value);
}

void UserDailyHoursWidget::updateWorkQuantity(const double value)
{
    switch (_idQuantity) {
    case DAILY_HOURS:
        ui->sbDailyHours->setValue(value);
        break;
    case WEEKLY_DAYS:
        ui->sbWeeklyDays->setValue(value);
        break;
    case MONTHLY_DAYS:
        ui->sbMonthlyDays->setValue(value);
        break;
    default:
        _idQuantity = DAILY_HOURS;
    }
    computeQuantityWork();
}

void UserDailyHoursWidget::computeQuantityWork() {
    ui->sbDailyHours->setValue(ui->sbDailyHours->value());
    ui->sbWeeklyDays->setValue(ui->sbWeeklyDays->value());
    ui->sbWeeklyHours->setValue(
                ui->sbDailyHours->value() * ui->sbWeeklyDays->value());
    ui->sbMonthlyDays->setValue(ui->sbMonthlyDays->value());
}
}
}
