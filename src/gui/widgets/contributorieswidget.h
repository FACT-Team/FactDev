#ifndef CONTRIBUTORIESWIDGET_H
#define CONTRIBUTORIESWIDGET_H

#include <QWidget>
#include <QStandardItem>
#include <QSpinBox>

#include "models/contributory.h"

#include "gui/widgets/widgetsmodels/contributoriestablemodel.h"
#include "gui/widgets/widgetsmodels/projectcontributoriestablemodel.h"

namespace Ui {
class ContributoriesWidget;
}

namespace Gui {
namespace Widgets {
class ContributoriesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ContributoriesWidget(QSharedPointer<Customer> c, QWidget *parent = 0);
    ~ContributoriesWidget();

    /**
     * @brief getContributories Get contributories List
     * @return
     */
    QList<Contributory> getContributories() const;
    int count();

    /**
     * @brief add Add the Contributory <i>c</i> in the model
     * @param c the <b>Contributory</b>
     */
    void add(QList<Contributory> &c);
    void add(Contributory &c);
public slots:
    /**
     * @brief add Add a new empty contributory
     */
    void add(void);

    /**
     * @brief remove Remove the current contributory
     */
    void remove(void);

    void addProject(void);
    void removeProject(void);
    void changeProject(void);
    void editing(void);
    void updateBtn(void);

signals:
    void contributoryChanged();
private:
    Ui::ContributoriesWidget *ui;
    QList<WdgModels::ContributoriesTableModel*> _modelsContributories;
    Gui::Widgets::WdgModels::ProjectContributoriesTableModel* _modelProjects;
    QSharedPointer<Customer> _customer;
};
}
}
#endif // CONTRIBUTORIESWIDGET_H
