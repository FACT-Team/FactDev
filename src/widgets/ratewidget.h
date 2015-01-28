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
     * @brief RateWidget::RateWidget Construct a rate widget
     * @param parent The QWidget parent
     */
    explicit RateWidget(QWidget *parent = 0);
    ~RateWidget();

    /**
     * @brief RateWidget::initRate Initialize the rate
     */
    void initRate();

    /**
     * @brief RateWidget::setWidgetDailyRateValue Modify the <i>value</i> of the
     *  daily rate spin box component
     * @param value New Value
     */
    void setWidgetDailyRateValue(double value);

    /**
     * @brief RateWidget::getDailyRate Get the daily rate
     * @return The daily rate
     */
    double getDailyRate();

    /**
     * @brief RateWidget::getHourlyRate Get the hourly rate
     * @return The hourly rate
     */
    double getHourlyRate();

    /**
     * @brief RateWidget::setWidgetHourlyRateValue Modify the <i>value</i> of the
     *  hourly rate spin box component
     * @param value New value
     */
    void setWidgetHourlyRateValue(double value);

    /**
     * @brief updateConversionRate Update daily rate or hourly rate
     */
    void updateConversionRate();

public slots:
    /**
     * @brief setDailyRate Set a new value for the daily rate
     * @param dailyRate The new daily rate
     */
    void setDailyRate();

    /**
     * @brief setHourlyRate Set a new value for the hourly rate
     * @param hourlyRate The new hourly rate
     */
    void setHourlyRate();



private:
    Ui::RateWidget *ui;         //!< User interface of <b>RateWidget</b>
    bool _isDailyRateModified;  /** boolean value to signal if the daily rate
                                 has been modified */
};

#endif // RATEWIDGET_H
