#ifndef CONTRIBUTORIESWIDGET_H
#define CONTRIBUTORIESWIDGET_H

#include <QWidget>
#include <QStandardItem>

#include "models/contributory.h"
#include "widgets/widgetsmodels/contributoriestablemodel.h"

namespace Ui {
class ContributoriesWidget;
}

class ContributoriesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ContributoriesWidget(QWidget *parent = 0);
    ~ContributoriesWidget();

    QList<Contributory> getContributories() const;
public slots:
    void add(void);
    void remove(void);
private:
    Ui::ContributoriesWidget *ui;
    ContributoriesTableModel* _model;
};

#endif // CONTRIBUTORIESWIDGET_H
