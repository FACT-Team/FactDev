#ifndef RATEWIDGET_H
#define RATEWIDGET_H

#include <QWidget>
#define LEGAL_RATE 9.61
#define NB_DAILY_HOURS 7
namespace Ui {
class RateWidget;
}

class RateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RateWidget(QWidget *parent = 0);
    ~RateWidget();

    void initRate();

    double getDailyRate();
    void setDailyRate(double dailyRate);

    double getHourlyRate();
    void setHourlyRate(double hourlyRate);

private:
    Ui::RateWidget *ui;
};

#endif // RATEWIDGET_H
