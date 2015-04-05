#include "filechosewidget.h"
#include "ui_filechosewidget.h"

FileChoseWidget::FileChoseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileChoseWidget)
{
    ui->setupUi(this);
}

FileChoseWidget::~FileChoseWidget()
{
    delete ui;
}
