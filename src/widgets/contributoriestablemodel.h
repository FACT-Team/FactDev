#ifndef CONTRIBUTORIESTABLEMODEL_H
#define CONTRIBUTORIESTABLEMODEL_H
#include <QObject>
#include <QAbstractTableModel>

#include "models/contributory.h"
class ContributoriesTableModel : public QAbstractTableModel
{
public:
    ContributoriesTableModel(QObject* parent = 0);
    ~ContributoriesTableModel();
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &) const;

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
     bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    void append(const Contributory & vehicle);
    void remove(const int a);
    Qt::ItemFlags flags(const QModelIndex & index) const ;

   QList<Contributory> getContributories();
private:
    QList<Contributory> _contributories;
};

#endif // CONTRIBUTORIESTABLEMODEL_H
