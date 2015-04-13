#ifndef COFFEEEASTEREGGWIDGET_H
#define COFFEEEASTEREGGWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include "gui/utils/image.h"

namespace Ui {
class CoffeeEasterEggWidget;
}

namespace Gui {
namespace Widgets {

/**
 * @brief The CoffeeState enum
 */
enum CoffeeState {
    INIT,
    FIRST_STEP,
    SECOND_STEP,
    THIRD_STEP,
    FOURTH_STEP,
    READY
};

/**
 * @author Florent Berbie
 * @brief The CoffeeEasterEggWidget class Easter egg class because we need
 * coffee
 */
class CoffeeEasterEggWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CoffeeEasterEggWidget::CoffeeEasterEggWidget Construct a
     *  CoffeeEasterEggWidget
     * @param parent QWidget parent
     */
    explicit CoffeeEasterEggWidget(QWidget *parent = 0);
    ~CoffeeEasterEggWidget();

    /**
     * @brief CoffeeEasterEggWidget::setupUI Init user interface
     */
    void setupUI();

    /**
     * @brief CoffeeEasterEggWidget::makeCoffeeFirstStep First step to make
     * coffee
     */
    void makeCoffeeFirstStep();

    /**
     * @brief CoffeeEasterEggWidget::makeCoffeeSecondStep Second step to make
     * coffee
     */
    void makeCoffeeSecondStep();

    /**
     * @brief CoffeeEasterEggWidget::makeCoffeeThirdStep Third step to make
     * coffee
     */
    void makeCoffeeThirdStep();

    /**
     * @brief CoffeeEasterEggWidget::makeCoffeeFourthStep Fourth step to make
     * coffee
     */
    void makeCoffeeFourthStep();

    /**
     * @brief CoffeeEasterEggWidget::makeCoffeeReadyStep Last step to make
     * coffee
     */
    void makeCoffeeReadyStep();

    /**
     * @brief CoffeeEasterEggWidget::isDrinked Return TRUE if coffee has been
     * drinked, else FALSE
     * @return boolean
     */
    bool isDrinked();

public slots:
    /**
     * @brief CoffeeEasterEggWidget::makeCoffeeInProgress Make Coffee
     */
    void makeCoffeeInProgress();

    /**
     * @brief CoffeeEasterEggWidget::nextState Go to the next state to make
     * coffee
     */
    void nextState();
private:
    Ui::CoffeeEasterEggWidget *ui;  //!< User interface
    QTimer *_timer;                 //!< Timer of coffeeMaker
    CoffeeState _state;             //!< current state to make coffee
    int _drinked;                   //!< coffee has been drinked
};
}
}

#endif // COFFEEEASTEREGGWIDGET_H
