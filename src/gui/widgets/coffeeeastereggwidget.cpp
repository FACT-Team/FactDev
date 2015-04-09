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
    _state = 0;
    _drinked = 0;
    ui->lbCoffee->setPixmap(
                Gui::Utils::Image::getImage(":/icons/img/coffee_level0.png"));
    ui->lbScreenControl->setText("<html><head/><body><p align=""center"">"
                                 "Pour bien bosser, il faut du café!"
                                 "</p></body></html>");
    ui->btnCoffeeMaker->setText("Faire le café !");
    ui->btnCoffeeMaker->setEnabled(true);
    /*
    ":/icons/img/coffee_level0.png"
    ":/icons/img/coffee_level1.png"
    ":/icons/img/coffee_level2.png"
    ":/icons/img/coffee_level3.png"
    ":/icons/img/coffee_level4.png"
    ":/icons/img/coffee_ready.png"
    */
}

void CoffeeEasterEggWidget::makeCoffeeInProgress() {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextState()));
    timer->start(1000);

}

void CoffeeEasterEggWidget::makeCoffeeFirstStep() {
    _state = 1;
    ui->lbCoffee->setPixmap(
                Gui::Utils::Image::getImage(":/icons/img/coffee_level1.png"));
    ui->lbScreenControl->setText("<html><head/><body><p align=""center"">"
                                 "Chauffage de l'eau..."
                                 "</p></body></html>");
    ui->btnCoffeeMaker->setText("Faire le café !");
    ui->btnCoffeeMaker->setEnabled(false);
}

void CoffeeEasterEggWidget::makeCoffeeSecondStep() {
    _state = 2;
    ui->lbCoffee->setPixmap(
                Gui::Utils::Image::getImage(":/icons/img/coffee_level2.png"));
    ui->lbScreenControl->setText("<html><head/><body><p align=""center"">"
                                 "En train de moudre le café..."
                                 "</p></body></html>");
    ui->btnCoffeeMaker->setText("Faire le café !");
    ui->btnCoffeeMaker->setEnabled(false);
}

void CoffeeEasterEggWidget::makeCoffeeThirdStep() {
    _state = 3;
    ui->lbCoffee->setPixmap(
                Gui::Utils::Image::getImage(":/icons/img/coffee_level3.png"));
    ui->lbScreenControl->setText("<html><head/><body><p align=""center"">"
                                 "Préparation du café"
                                 "</p></body></html>");
    ui->btnCoffeeMaker->setText("Faire le café !");
    ui->btnCoffeeMaker->setEnabled(false);
}

void CoffeeEasterEggWidget::makeCoffeeFourthStep() {
    _state = 4;
    ui->lbCoffee->setPixmap(
                Gui::Utils::Image::getImage(":/icons/img/coffee_level4.png"));
    ui->lbScreenControl->setText("<html><head/><body><p align=""center"">"
                                 "Préparation du café..."
                                 "</p></body></html>");
    ui->btnCoffeeMaker->setText("Faire le café !");
    ui->btnCoffeeMaker->setEnabled(false);
}

void CoffeeEasterEggWidget::makeCoffeeReadyStep() {
    _state = 5;
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
        setupUI();
    }

}

bool CoffeeEasterEggWidget::isDrinked() {
    return _drinked == 3;
}

void CoffeeEasterEggWidget::nextState() {
    switch(_state) {
    case 0:
        setupUI();
        break;
    case 1:
        makeCoffeeFirstStep();
        break;
    case 2:
        makeCoffeeSecondStep();
        break;
    case 3:
        makeCoffeeThirdStep();
        break;
    case 4:
        makeCoffeeFourthStep();
        break;
    case 5:
        makeCoffeeReadyStep();
        break;
    default:
        setupUI();
    }
}


}
}
