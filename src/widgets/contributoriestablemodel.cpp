#include "contributoriestablemodel.h"

ContributoriesTableModel::ContributoriesTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

ContributoriesTableModel::~ContributoriesTableModel()
{

}

int ContributoriesTableModel::rowCount(const QModelIndex &) const {
    return _contributories.count();
}

int ContributoriesTableModel::columnCount(const QModelIndex &) const {
    return 2;
}

QVariant ContributoriesTableModel::data(const QModelIndex &index, int role) const {
    if (role != Qt::DisplayRole && role != Qt::EditRole) return QVariant();
    const Contributory & vehicle = _contributories[index.row()];
    switch (index.column()) {
    case 0: return vehicle.getId();
    case 1: return vehicle.getProject().getName();
        //        case 2: return vehicle.registrationNumber();
    default: return QVariant();
    };
}

QVariant ContributoriesTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation != Qt::Horizontal) return QVariant();
    if (role != Qt::DisplayRole) return QVariant();
    switch (section) {
    case 0: return "ID";
    case 1: return "PROJECT";
    default: return QVariant();
    }
}

void ContributoriesTableModel::append(const Contributory &vehicle) {
    beginInsertRows(QModelIndex(), _contributories.count(), _contributories.count());
    _contributories.append(vehicle);
    endInsertRows();
}

