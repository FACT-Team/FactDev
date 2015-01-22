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


}

ContributoriesWidget::~ContributoriesWidget()
{
    delete ui;
}
QList<Contributory *> ContributoriesWidget::getContributories() const
{
    return _contributories;
}

void ContributoriesWidget::setContributories(const QList<Contributory *> &contributories)
{
    _contributories = contributories;
}

