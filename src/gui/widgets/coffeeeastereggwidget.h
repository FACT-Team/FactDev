#ifndef COFFEEEASTEREGGWIDGET_H
#define COFFEEEASTEREGGWIDGET_H

#include <QWidget>
#include <QTimer>
#include "gui/utils/image.h"

namespace Ui {
class CoffeeEasterEggWidget;
}

namespace Gui {
namespace Widgets {

/**
 * @brief The CoffeeEasterEggWidget class
 */
class CoffeeEasterEggWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CoffeeEasterEggWidget
     * @param parent
     */
    explicit CoffeeEasterEggWidget(QWidget *parent = 0);
    ~CoffeeEasterEggWidget();

    void setupUI();

    void makeCoffeeInProgress();

    void makeCoffeeFirstStep();
    void makeCoffeeSecondStep();
    void makeCoffeeThirdStep();
    void makeCoffeeFourthStep();
    void makeCoffeeReadyStep();
    bool isDrinked();

public slots:
    void nextState();
private:
    Ui::CoffeeEasterEggWidget *ui;
    int _state;
    int _drinked;

};
}
}

#endif // COFFEEEASTEREGGWIDGET_H
