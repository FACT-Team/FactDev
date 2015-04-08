#include "projectswidget.h"
#include "ui_projectswidget.h"

namespace Gui {
namespace Widgets {
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
   emit addProject();
}

void ProjectsWidget::editSelectedProject() {
    emit editProject();
}

void ProjectsWidget::removeSelectedProject() {
    emit removeProject();
}

void ProjectsWidget::updateBtn(bool b, bool remove, bool isLocked) {
    ui->btnDeleteProject->setEnabled(b && remove);
    ui->btnEditProject->setEnabled(b);
    ui->btnLockProject->setEnabled(!isLocked);
}

void ProjectsWidget::lockSelectedProject()
{
    emit lockProject();
}


}
}
