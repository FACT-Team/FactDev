#ifndef USERDAILYHOURSWIDGET_H
#define USERDAILYHOURSWIDGET_H

#include <QWidget>

namespace Ui {
class UserDailyHoursWidget;
}

namespace Gui {
namespace Widgets {

/**
 * @brief The UserDailyHoursWidget class Define user quantity of work
 */
class UserDailyHoursWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief UserDailyHoursWidget::UserDailyHoursWidget Cosntruct an
     *  UserDailyHoursWidget
     * @param parent QWidget parent
     */
    explicit UserDailyHoursWidget(QWidget *parent = 0);
    ~UserDailyHoursWidget();

    /**
     * @brief UserDailyHoursWidget::setupUI Init the User Interface
     */
    void setupUI();
public slots:
    /**
     * @brief UserDailyHoursWidget::dailyHoursValueHasChanged Daily hours
     * <i>value</i> has been changed
     * @param value New daily hours value
     */
    void dailyHoursValueHasChanged(const double value);

    /**
     * @brief UserDailyHoursWidget::weeklyDaysValueHasChanged Weekly days
     * <i>value</i> has been changed
     * @param value New Weekly days value
     */
    void weeklyDaysValueHasChanged(const double value);

    /**
     * @brief UserDailyHoursWidget::monthlyDaysValueHasChanged monthly days
     * <i>value</i> has been changed
     * @param value New monthly daysz value
     */
    void monthlyDaysValueHasChanged(const double value);


private:
    Ui::UserDailyHoursWidget *ui;       //!< User interface
    int _idQuantity;                    //!< Number of quandtity change
    static const int DAILY_HOURS = 1;   //!< daily hours constant
    static const int WEEKLY_DAYS = 2;   //!< weekly days constant
    static const int MONTHLY_DAYS = 3;  //!< monthly days constant

    /**
     * @brief UserDailyHoursWidget::updateWorkQuantity Update work quantity
     * defined by <i>value</i>
     * @param valueWork quantity value
     */
    void updateWorkQuantity(const double value);

    /**
     * @brief UserDailyHoursWidget::computeQuantityWork Refresh user
     * interface with the correct computed values.
     */
    void computeQuantityWork();
};
}
}
#endif // USERDAILYHOURSWIDGET_H
