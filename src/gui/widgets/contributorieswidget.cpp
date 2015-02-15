#include "contributorieswidget.h"
#include "models/contributory.h"
#include "gui/widgets/delegates/projectcombodelegate.h"
#include "ui_contributorieswidget.h"

namespace Gui {
namespace Widgets {
ContributoriesWidget::ContributoriesWidget(QSharedPointer<Customer> c, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContributoriesWidget)
{
    ui->setupUi(this);
    _model  = new WdgModels::ContributoriesTableModel();
    Delegates::ProjectComboDelegate* delegate = new Delegates::ProjectComboDelegate(c);
    ui->tblContributories->setItemDelegateForColumn(0, delegate);
    ui->tblContributories->setModel(_model);
    ui->tblContributories->setEditTriggers(QAbstractItemView::DoubleClicked);

    ui->tblContributories->setColumnWidth(0, 150);
    ui->tblContributories->setColumnWidth(1, 350);
    ui->tblContributories->setColumnWidth(2, 150);
    emit contributoryChanged();
}

ContributoriesWidget::~ContributoriesWidget()
{
    delete ui;
}

QList<Contributory> ContributoriesWidget::getContributories() const
{
    return _model->getContributories();
}

void ContributoriesWidget::add()
{
    _model->append(Contributory());
    emit contributoryChanged();
}

void ContributoriesWidget::add(Contributory c)
{
    _model->append(c);
    emit contributoryChanged();
}

void ContributoriesWidget::remove()
{
    if (ui->tblContributories->selectionModel()->hasSelection()) {
        _model->remove(ui->tblContributories->currentIndex().row());
    }
    emit contributoryChanged();
}

int ContributoriesWidget::count() {
    return _model->count();
}
}
}
