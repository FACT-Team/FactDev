#ifndef CONTRIBUTORIESWIDGET_H
#define CONTRIBUTORIESWIDGET_H

#include <QWidget>
#include <QStandardItem>
#include <QSpinBox>

#include "models/contributory.h"
#include "models/contributorieslist.h"
#include "models/contributory.h"
#include "models/contributorieslist.h"

#include "gui/widgets/widgetsmodels/contributoriestablemodel.h"
#include "gui/widgets/widgetsmodels/projectcontributoriestablemodel.h"
#include "gui/widgets/delegates/projectcombodelegate.h"
#include "gui/widgets/delegates/doublespinboxdelegate.h"
#include "gui/widgets/delegates/unitcombodelegate.h"

namespace Ui {
class ContributoriesWidget;
}

namespace Gui {
namespace Widgets {
/**
 * @brief The ContributoriesWidget class Widget of Contributories
 */
class ContributoriesWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief ContributoriesWidget::ContributoriesWidget Construct a
     * ContributoriesWidget
     * @param c Customer
     * @param parent Widget parent
     */
    explicit ContributoriesWidget(
            QSharedPointer<Customer> c, QWidget *parent = 0);
    ~ContributoriesWidget();

    /**
     * @brief ContributoriesWidget::getContributories Get contributories List
     * @return ContributoriesList
     */
    ContributoriesList* getContributories() const;
    /**
     * @brief ContributoriesWidget::count Numbers of contributories
     * @return Numbers of contributories
     */
    int count();

    /**
     * @brief ContributoriesWidget::add Add contributorieslist <i>list</i> in
     * the model
     * @param list the <b>ContributoriesList</b>
     */
    void add(ContributoriesList &list);
public slots:
    /**
     * @brief ContributoriesWidget::add Add a new empty contributory
     */
    void add(void);

    /**
     * @brief ContributoriesWidget::remove Remove the current contributory
     */
    void remove(void);

    /**
     * @brief ContributoriesWidget::addProject Add a Projet and it rate <i>p</i>
     * @param p Rate linked to Project
     */
    void addProject(QPair<Project *, Rate> *p=0);

    /**
     * @brief ContributoriesWidget::removeProject Remove the current Project
     */
    void removeProject(void);

    /**
     * @brief ContributoriesWidget::changeProject Change the current Project
     */
    void changeProject(void);

    /**
     * @brief ContributoriesWidget::editing Remove the current Project in the
     * combobox not used
     */
    void editing(void);

    /**
     * @brief ContributoriesWidget::updateUi Update the User Interface
     */
    void updateUi(void);

    /**
     * @brief ContributoriesWidget::updatePrice Update total price
     */
    void updatePrice(void);

signals:
    /**
     * @brief ContributoriesWidget::contributoryChanged Signal that a
     * contributory has changed
     */
    void contributoryChanged();
private:
    Ui::ContributoriesWidget *ui;   //!< User interface
    //!< Model of contributories
    QList<WdgModels::ContributoriesTableModel*> _modelsContributories;

    //!< Model of contributories to removed
    QList<WdgModels::ContributoriesTableModel*> _modelsContributoriesToRemoved;

    //!< Model of Projects
    WdgModels::ProjectContributoriesTableModel* _modelProjects;

    //!< Customer
    QSharedPointer<Customer> _customer;
};
}
}
#endif // CONTRIBUTORIESWIDGET_H
