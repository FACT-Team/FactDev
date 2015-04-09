#include "coffeeeastereggwidget.h"
#include "ui_coffeeeastereggwidget.h"

CoffeeEasterEggWidget::CoffeeEasterEggWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CoffeeEasterEggWidget)
{
    ui->setupUi(this);
}

CoffeeEasterEggWidget::~CoffeeEasterEggWidget()
{
    delete ui;
}
