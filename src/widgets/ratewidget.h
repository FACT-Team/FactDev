#ifndef RATEWIDGET_H
#define RATEWIDGET_H

#include <QWidget>

namespace Ui {
class RateWidget;
}

class RateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RateWidget(QWidget *parent = 0);
    ~RateWidget();

    double getDailyRate();
    void setDailyRate(double dailyRate);

    double getHourlyRate();
    void setHourlyRate(double hourlyRate);

private:
    Ui::RateWidget *ui;
};

#endif // RATEWIDGET_H
