#include "contributorieswidget.h"
#include "ui_contributorieswidget.h"


ContributoriesWidget::ContributoriesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContributoriesWidget)
{
    ui->setupUi(this);
    _model  = new ContributoriesTableModel();
    ui->tblContributories->setModel(_model);
    Contributory c;
    Project p;
    p.setDescription("coucou");
    p.setName("test");
    c.setProject(p);
    _model->append(c);
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

