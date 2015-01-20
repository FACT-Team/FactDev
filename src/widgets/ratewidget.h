#ifndef RATEWIDGET_H
#define RATEWIDGET_H

#include <QWidget>
#define LEGAL_RATE 9.61
#define NB_DAILY_HOURS 7
namespace Ui {
class RateWidget;
}

/**
 * @brief Class for display Rate
 * @author Florent Berbie
 */
class RateWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief RateWidget Construct a rate widget
     * @param parent The QWidget parent
     */
    explicit RateWidget(QWidget *parent = 0);
    ~RateWidget();

    /**
     * @brief initRate Initialize the rate
     */
    void initRate();

    /**
     * @brief getDailyRate
     * @return The daily rate
     */
    double getDailyRate();

    /**
     * @brief setDailyRate Set a new value for the daily rate
     * @param dailyRate The new daily rate
     */
    void setDailyRate(double dailyRate);

    /**
     * @brief getHourlyRate
     * @return The hourly rate
     */
    double getHourlyRate();

    /**
     * @brief setHourlyRate Set a new value for the hourly rate
     * @param hourlyRate The new hourly rate
     */
    void setHourlyRate(double hourlyRate);

private:
    Ui::RateWidget *ui; //!<
};

#endif // RATEWIDGET_H
