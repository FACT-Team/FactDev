#include "projectswidget.h"
#include "ui_projectswidget.h"

ProjectsWidget::ProjectsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectsWidget)
{
    ui->setupUi(this);
}

ProjectsWidget::~ProjectsWidget()
{
    delete ui;
}
