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
}

void CoffeeEasterEggWidget::makeCoffeeInProgress() {
    _timer = new QTimer(this);
    _state = 1;
    connect(_timer, SIGNAL(timeout()), this, SLOT(nextState()));
    _timer->start(1000);
    qDebug() << "makeCoffeeInProgress";

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
    _state = 2;
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
    _state = 3;
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
    _state = 4;
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
    _state = 5;
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
        _timer->stop();
        delete _timer;
        setupUI();        

    }

}

bool CoffeeEasterEggWidget::isDrinked() {
    return _drinked == 3;
}

void CoffeeEasterEggWidget::nextState() {
    qDebug() << "nextState -->" + _state;
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
