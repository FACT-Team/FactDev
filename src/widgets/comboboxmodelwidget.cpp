#include "comboboxmodelwidget.h"
#include "ui_comboboxmodelwidget.h"

ComboBoxModelWidget::ComboBoxModelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComboBoxModelWidget)
{

    ui->setupUi(this);
    //ui->cbModel->setModel(customerData.instance()->getCustomersTable());
}

ComboBoxModelWidget::~ComboBoxModelWidget()
{
    delete ui;
}
