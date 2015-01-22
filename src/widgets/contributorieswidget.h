#ifndef CONTRIBUTORIESWIDGET_H
#define CONTRIBUTORIESWIDGET_H

#include <QWidget>
#include <QStandardItem>

#include "models/contributory.h"
#include "widgets/contributoriestablemodel.h"

namespace Ui {
class ContributoriesWidget;
}

class ContributoriesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ContributoriesWidget(QWidget *parent = 0);
    ~ContributoriesWidget();

    QList<Contributory *> getContributories() const;
    void setContributories(const QList<Contributory *> &getContributories);
public slots:
    void add(void);
    void remove(void);
private:
    Ui::ContributoriesWidget *ui;
    QList<Contributory*> _contributories;

    ContributoriesTableModel* _model;
};

#endif // CONTRIBUTORIESWIDGET_H
