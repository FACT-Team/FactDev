#ifndef PROJECTSWIDGET_H
#define PROJECTSWIDGET_H

#include <QWidget>

namespace Ui {
class ProjectsWidget;
}

/**
 * @brief The ProjectsWidget class
 * @author Florent Berbie
 */
class ProjectsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectsWidget(QWidget *parent = 0);
    ~ProjectsWidget();
public slots:
    void newProject();
    void editSelectedProject();
    void removeSelectedProject();
signals:
    void addProject();
    void editProject();
    void removeProject();

private:
    Ui::ProjectsWidget *ui;
};

#endif // PROJECTSWIDGET_H
