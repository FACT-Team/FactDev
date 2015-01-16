#ifndef PROJECTSWIDGET_H
#define PROJECTSWIDGET_H

#include <QWidget>

namespace Ui {
class ProjectsWidget;
}

class ProjectsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectsWidget(QWidget *parent = 0);
    ~ProjectsWidget();

private:
    Ui::ProjectsWidget *ui;
};

#endif // PROJECTSWIDGET_H
