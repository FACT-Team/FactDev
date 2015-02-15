#ifndef PROJECTSWIDGET_H
#define PROJECTSWIDGET_H

#include <QWidget>

#include "gui/dialogs/addprojectdialog.h"

namespace Ui {
class ProjectsWidget;
}

namespace Gui {
namespace Widgets {
/**
 * @author Florent Berbie
 * @brief The ProjectsWidget class Actions on Project
 */
class ProjectsWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief ProjectsWidget::ProjectsWidget Construct a ProjectsWidget
     * @param parent
     */
    explicit ProjectsWidget(QWidget *parent = 0);
    ~ProjectsWidget();

public slots:
    /**
     * @brief ProjectsWidget::newProject Event which sends a signal to add a new
     * project
     */
    void newProject();
    /**
     * @brief ProjectsWidget::editSelectedProject Event which sends a signal to
     * edit the project selected
     */
    void editSelectedProject();

    /**
     * @brief ProjectsWidget::removeSelectedProject Event which sends a signal
     * to remove the project selected
     */
    void removeSelectedProject();

    /**
     * @brief ProjectsWidget::updateBtn Update the toolbar in tblProjects
     * @param boolean if a row is selected
     */
    void updateBtn(bool b);

signals:
    /**
     * @brief ProjectsWidget::addProject Add a new project to the current
     * Customer
     */
    void addProject();

    /**
     * @brief ProjectsWidget::editProject Edit the current Customer selected
     */
    void editProject();

    /**
     * @brief ProjectsWidget::removeProject Remove the current Customer selected
     */
    void removeProject();

private:
    Ui::ProjectsWidget *ui; //!< User interface of <b>ProjectsWidget</b>
};
}
}
#endif // PROJECTSWIDGET_H
