#include "comboboxmodelwidget.h"
#include "ui_comboboxmodelwidget.h"

ComboBoxModelWidget::ComboBoxModelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComboBoxModelWidget)
{
    ui->setupUi(this);
}

ComboBoxModelWidget::~ComboBoxModelWidget()
{
    delete ui;
}
