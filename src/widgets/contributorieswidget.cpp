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
    _model->remove(ui->tblContributories->currentIndex().row());
}

