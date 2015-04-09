#ifndef COFFEEEASTEREGGWIDGET_H
#define COFFEEEASTEREGGWIDGET_H

#include <QWidget>

namespace Ui {
class CoffeeEasterEggWidget;
}

class CoffeeEasterEggWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CoffeeEasterEggWidget(QWidget *parent = 0);
    ~CoffeeEasterEggWidget();

private:
    Ui::CoffeeEasterEggWidget *ui;
};

#endif // COFFEEEASTEREGGWIDGET_H
