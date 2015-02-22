#include "contributorieswidget.h"
#include "models/contributory.h"
#include "gui/widgets/delegates/projectcombodelegate.h"
#include "gui/widgets/delegates/doublespinboxdelegate.h"
#include "gui/widgets/delegates/unitcombodelegate.h"
#include "models/contributorieslist.h"
#include "ui_contributorieswidget.h"

namespace Gui {
namespace Widgets {

ContributoriesWidget::ContributoriesWidget(QSharedPointer<Customer> c, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContributoriesWidget)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(1, 1);
    _modelProjects = new WdgModels::ProjectContributoriesTableModel();
    _customer = c;
    Delegates::ProjectComboDelegate* d = new Delegates::ProjectComboDelegate(c);
    d->setLocked(true);
    ui->tblProjects->setItemDelegateForColumn(0, d);
    ui->tblProjects->setItemDelegateForColumn(1, new Delegates::DoubleSpinBoxDelegate());
    ui->tblProjects->setItemDelegateForColumn(2, new Delegates::DoubleSpinBoxDelegate());
    ui->tblProjects->setModel(_modelProjects);
    ui->btnAddPrestation->hide();
    ui->btnRmovePrestation->hide();
    connect(ui->tblProjects->itemDelegateForColumn(0), SIGNAL(closeEditor(QWidget*)), SLOT(editing()));
    emit contributoryChanged();
    emit updateUi();
}

ContributoriesWidget::~ContributoriesWidget()
{
    delete ui;
}

ContributoriesList* ContributoriesWidget::getContributories() const
{
    int i = 0;
    ContributoriesList* contribList = new ContributoriesList();
    for(QPair<Models::Project*, Models::Rate> pair : _modelProjects->getProjects()) {
        contribList->addProject(pair.first, pair.second);

        for(Contributory& c : _modelsContributories[i++]->getContributories()) {
            if(!c.isToRemoved() || c.getId() != 0) {
                c.setProject(pair.first);
                contribList->addContributory(c);
            }
        }

        for(WdgModels::ContributoriesTableModel* model : _modelsContributoriesToRemoved) {
            for(Contributory& c : model->getContributories()) {
                c.setProject(pair.first);
                c.setToRemoved(true);
                contribList->addContributory(c);
            }
        }
    }
    return contribList;
}

void ContributoriesWidget::add()
{
    _modelsContributories[ui->stack->currentIndex()]->append(Contributory());
    emit contributoryChanged();
}

void ContributoriesWidget::add(ContributoriesList& list)
{
    for(Project* p : list.getProjects()) {
        addProject(new QPair<Project*, Rate>(p, list.getRate(p)));
        for(Contributory c :list.getContributories(p)) {
            _modelsContributories.last()->append(c);
        }
    }
    emit contributoryChanged();
}

void ContributoriesWidget::remove(void)
{
    QTableView* view = (QTableView*)ui->stack->currentWidget();
    if (view->selectionModel()->hasSelection()) {
        _modelsContributories[ui->stack->currentIndex()]->remove(view->currentIndex().row());
    }
    emit contributoryChanged();
}

void ContributoriesWidget::addProject(QPair<Project*, Rate>* p)
{
    if(p == 0) {
        _modelProjects->append();
    } else {
        _modelProjects->append(*p);
    }
    QTableView* view = new QTableView();
    _modelsContributories << new WdgModels::ContributoriesTableModel();
    view->setModel(_modelsContributories.last());
    view->setEditTriggers(QAbstractItemView::DoubleClicked);
    view->setItemDelegateForColumn(1, new Delegates::DoubleSpinBoxDelegate());
    view->setItemDelegateForColumn(2, new Delegates::UnitComboDelegate());
    view->setColumnWidth(0, 450);
    view->setColumnWidth(1, 100);
    view->setColumnWidth(2, 100);
    connect(view->itemDelegateForColumn(2), SIGNAL(closeEditor(QWidget*)), SLOT(updatePrice()));
    connect(view->itemDelegateForColumn(1), SIGNAL(closeEditor(QWidget*)), SLOT(updatePrice()));
    ui->stack->insertWidget(ui->stack->count(), view);
    emit updateUi();
}

void ContributoriesWidget::removeProject(void)
{
    _modelsContributoriesToRemoved << _modelsContributories[ui->tblProjects->currentIndex().row()];
    _modelsContributories.removeAt(ui->tblProjects->currentIndex().row());
    _modelProjects->remove(ui->tblProjects->currentIndex().row());
    ui->stack->removeWidget(ui->stack->currentWidget());
    ui->stack->setCurrentIndex(0);

    emit updateUi();
}

void ContributoriesWidget::changeProject()
{
    ui->stack->setCurrentIndex(ui->tblProjects->currentIndex().row());
    emit updateUi();
}

void ContributoriesWidget::editing()
{
    ((Delegates::ProjectComboDelegate*)ui->tblProjects->itemDelegateForColumn(0))->removeInCombo(_modelProjects->getSelectedProjects());
    emit updateUi();
}

void ContributoriesWidget::updateUi()
{
    ui->btnAddProject->setEnabled(_modelProjects->getSelectedProjects().count() <
                                  ((Delegates::ProjectComboDelegate*)ui->tblProjects->itemDelegateForColumn(0))->getProjects().count() &&
                                  _modelProjects->allProjectsChose());
    ui->btnRemoveProject->setEnabled(ui->tblProjects->currentIndex().row() != -1);

    if(_modelProjects->getSelectedProjects().count() > 0) {
        ui->btnAddPrestation->show();
        ui->btnRmovePrestation->show();
    } else {
        ui->btnAddPrestation->hide();
        ui->btnRmovePrestation->hide();
    }
    updatePrice();
}

void ContributoriesWidget::updatePrice()
{
    // TODO put me in Billing
    if(_modelsContributories.count() > 0) {
        WdgModels::ContributoriesTableModel* currentContributory = _modelsContributories[ui->stack->currentIndex()];
        QPair<Models::Project*, Models::Rate> currentProject = _modelProjects->getProject(ui->stack->currentIndex());

        ui->sbSubSum->setValue(currentContributory->getSumQuantity() * currentProject.second.getHourlyRate());
        double value = 0.0;
        int i = 0;
        for(WdgModels::ContributoriesTableModel* contributory : _modelsContributories) {
            value += contributory->getSumQuantity() * _modelProjects->getProject(i++).second.getHourlyRate();
        }
        ui->sbAllSums->setValue(value);
    }
}

int ContributoriesWidget::count() {
    return _modelsContributories.count() > 0 && _modelProjects->getProjects().count() > 0;
}

}
}
