#include "contributorieswidget.h"
#include "models/contributory.h"
#include "gui/widgets/delegates/projectcombodelegate.h"
#include "gui/widgets/delegates/doublespinboxdelegate.h"
#include "ui_contributorieswidget.h"

namespace Gui {
namespace Widgets {
ContributoriesWidget::ContributoriesWidget(QSharedPointer<Customer> c, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContributoriesWidget)
{
    ui->setupUi(this);
    _modelProjects = new WdgModels::ProjectContributoriesTableModel();
    _customer = c;
    ui->tblProjects->setItemDelegateForColumn(0, new Delegates::ProjectComboDelegate(c));
    ui->tblProjects->setItemDelegateForColumn(1, new Delegates::DoubleSpinBoxDelegate());
    ui->tblProjects->setItemDelegateForColumn(2, new Delegates::DoubleSpinBoxDelegate());
    ui->tblProjects->setModel(_modelProjects);
    emit contributoryChanged();
}

ContributoriesWidget::~ContributoriesWidget()
{
    delete ui;
}

QList<Contributory> ContributoriesWidget::getContributories() const
{
//    return _modelContributories->getContributories();
}

void ContributoriesWidget::add()
{
    _modelsContributories[ui->stack->currentIndex()]->append(Contributory());
    emit contributoryChanged();
}

void ContributoriesWidget::add(Contributory& c)
{
    _modelsContributories[ui->stack->currentIndex()]->append(c);
    emit contributoryChanged();
}

void ContributoriesWidget::add(QList<Contributory>& contributories)
{
    for(Contributory& c : contributories) {
        add(c);
    }
}

void ContributoriesWidget::remove(void)
{
//    if (ui->tblContributories->selectionModel()->hasSelection()) {
//        _modelContributories->remove(ui->tblContributories->currentIndex().row());
//    }
    emit contributoryChanged();
}

void ContributoriesWidget::addProject(void)
{
    qDebug() << "Yeah ! I add a new project :)";
    _modelProjects->append();
    QTableView* view = new QTableView();
    _modelsContributories << new WdgModels::ContributoriesTableModel();
    view->setModel(_modelsContributories.last());
    view->setEditTriggers(QAbstractItemView::DoubleClicked);

    view->setColumnWidth(0, 150);
    view->setColumnWidth(1, 350);
    view->setColumnWidth(2, 150);

    ui->stack->insertWidget(ui->stack->count(), view);
//    table->horizontalHeader()->setResizeMode( 0, QHeaderView::Stretch );
//    table->horizontalHeader()->setResizeMode( 1, QHeaderView::ResizeToContents );
}

void ContributoriesWidget::removeProject(void)
{
    qDebug() << "I want to remove this project :-(";
    _modelProjects->remove(ui->tblProjects->currentIndex().row());
}

void ContributoriesWidget::changeProject()
{
    ui->stack->setCurrentIndex(ui->tblProjects->currentIndex().row());
}

void ContributoriesWidget::editing()
{
    ((Delegates::ProjectComboDelegate*)ui->tblProjects->itemDelegateForColumn(0))->removeInCombo(_modelProjects->getSelectedProjects());
}

int ContributoriesWidget::count() {
    //return _modelContributories->count();
}

}
}
