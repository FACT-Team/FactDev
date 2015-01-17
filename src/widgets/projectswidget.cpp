#include "projectswidget.h"
#include "dialogs/addprojectdialog.h"
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

void ProjectsWidget::newProject()
{
    AddProjectDialog win;
    if (win.exec()) {

    }

}

void ProjectsWidget::editSelectedProject()
{

}

void ProjectsWidget::removeSelectedProject()
{

}
