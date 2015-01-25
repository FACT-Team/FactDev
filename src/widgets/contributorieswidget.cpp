#include "contributorieswidget.h"
#include "models/contributory.h"
#include "widgets/delegates/projectcombodelegate.h"
#include "ui_contributorieswidget.h"


ContributoriesWidget::ContributoriesWidget(Customer*c, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContributoriesWidget)
{
    ui->setupUi(this);
    _model  = new ContributoriesTableModel();
    ProjectComboDelegate* delegate = new ProjectComboDelegate(c);
    ui->tblContributories->setItemDelegateForColumn(0, delegate);
    ui->tblContributories->setModel(_model);
    ui->tblContributories->setEditTriggers(QAbstractItemView::DoubleClicked);

    ui->tblContributories->setColumnWidth(0, 150);
    ui->tblContributories->setColumnWidth(1, 350);
    ui->tblContributories->setColumnWidth(2, 150);

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
}

void ContributoriesWidget::remove()
{
    if (ui->tblContributories->selectionModel()->hasSelection()) {
        _model->remove(ui->tblContributories->currentIndex().row());
    }
}

