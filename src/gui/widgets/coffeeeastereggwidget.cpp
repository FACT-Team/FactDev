#include "coffeeeastereggwidget.h"
#include "ui_coffeeeastereggwidget.h"

namespace Gui {
namespace Widgets {
CoffeeEasterEggWidget::CoffeeEasterEggWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CoffeeEasterEggWidget)
{
    ui->setupUi(this);
    setupUI();
}

CoffeeEasterEggWidget::~CoffeeEasterEggWidget()
{
    delete ui;
}

void CoffeeEasterEggWidget::setupUI() {
    _state = INIT;
    _drinked = 0;
    ui->lbCoffee->setPixmap(
                Gui::Utils::Image::getImage(":/icons/img/coffee_level0.png"));
    ui->lbScreenControl->setText("<html><head/><body><p align=""center"">"
                                 "Pour bien bosser, il faut du café!"
                                 "</p></body></html>");
    ui->btnCoffeeMaker->setText("Faire le café !");
    ui->btnCoffeeMaker->setEnabled(true);
}

void CoffeeEasterEggWidget::makeCoffeeInProgress() {
    _timer = new QTimer(this);
    _state = FIRST_STEP;
    connect(_timer, SIGNAL(timeout()), this, SLOT(nextState()));
    _timer->start(1000);
}

void CoffeeEasterEggWidget::makeCoffeeFirstStep() {
    _state = FIRST_STEP;
    ui->lbCoffee->setPixmap(
                Gui::Utils::Image::getImage(":/icons/img/coffee_level1.png"));
    ui->lbScreenControl->setText("<html><head/><body><p align=""center"">"
                                 "Chauffage de l'eau..."
                                 "</p></body></html>");
    ui->btnCoffeeMaker->setText("Faire le café !");
    ui->btnCoffeeMaker->setEnabled(false);
    _state = SECOND_STEP;
}

void CoffeeEasterEggWidget::makeCoffeeSecondStep() {
    _state = SECOND_STEP;
    ui->lbCoffee->setPixmap(
                Gui::Utils::Image::getImage(":/icons/img/coffee_level2.png"));
    ui->lbScreenControl->setText("<html><head/><body><p align=""center"">"
                                 "En train de moudre le café..."
                                 "</p></body></html>");
    ui->btnCoffeeMaker->setText("Faire le café !");
    ui->btnCoffeeMaker->setEnabled(false);
   _state = THIRD_STEP;
}

void CoffeeEasterEggWidget::makeCoffeeThirdStep() {
   _state = THIRD_STEP;
    ui->lbCoffee->setPixmap(
                Gui::Utils::Image::getImage(":/icons/img/coffee_level3.png"));
    ui->lbScreenControl->setText("<html><head/><body><p align=""center"">"
                                 "Préparation du café"
                                 "</p></body></html>");
    ui->btnCoffeeMaker->setText("Faire le café !");
    ui->btnCoffeeMaker->setEnabled(false);
    _state = FOURTH_STEP;
}

void CoffeeEasterEggWidget::makeCoffeeFourthStep() {
    _state = FOURTH_STEP;
    ui->lbCoffee->setPixmap(
                Gui::Utils::Image::getImage(":/icons/img/coffee_level4.png"));
    ui->lbScreenControl->setText("<html><head/><body><p align=""center"">"
                                 "Préparation du café..."
                                 "</p></body></html>");
    ui->btnCoffeeMaker->setText("Faire le café !");
    ui->btnCoffeeMaker->setEnabled(false);
    _state = READY;
}

void CoffeeEasterEggWidget::makeCoffeeReadyStep() {
    _state = READY;
    if (!isDrinked()) {
        ui->lbCoffee->setPixmap(
                    Gui::Utils::Image::getImage(":/icons/img/coffee_ready.png"));
        ui->lbScreenControl->setText("<html><head/><body><p align=""center"">"
                                     "Café prêt :)"
                                     "</p></body></html>");
        ui->btnCoffeeMaker->setText("Faire le café !");
        ui->btnCoffeeMaker->setEnabled(false);
        _drinked++;
    } else {
        _timer->stop();
        delete _timer;
        setupUI();        

    }

}

bool CoffeeEasterEggWidget::isDrinked() {
    return _drinked == 3;
}

void CoffeeEasterEggWidget::nextState() {
    switch(_state) {
    case INIT:
        setupUI();
        break;
    case FIRST_STEP:
        makeCoffeeFirstStep();
        break;
    case SECOND_STEP:
        makeCoffeeSecondStep();
        break;
    case THIRD_STEP:
        makeCoffeeThirdStep();
        break;
    case FOURTH_STEP:
        makeCoffeeFourthStep();
        break;
    case READY:
        makeCoffeeReadyStep();
        break;
    default:
        setupUI();
    }

}


}
}
