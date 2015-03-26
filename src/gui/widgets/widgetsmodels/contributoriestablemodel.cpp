#include "contributoriestablemodel.h"

namespace Gui {
namespace Widgets {
namespace WdgModels {

ContributoriesTableModel::ContributoriesTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

ContributoriesTableModel::~ContributoriesTableModel() {
    clear();
}

int ContributoriesTableModel::rowCount(const QModelIndex &) const {
    return _contributories.count();
}

int ContributoriesTableModel::columnCount(const QModelIndex &) const {
    return 4;
}

QVariant ContributoriesTableModel::data(
        const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole && role != Qt::EditRole) {
        return QVariant();
    }
    Models::Rate r;

    const Contributory & contributory = _contributories[index.row()];
//    qDebug() << "=)" << contributory.getUnit().getype();

    switch (index.column()) {
    case 0: return contributory.getDescription();
    case 1: return contributory.getLongDescription();
    case 2: return contributory.getQuantity()/r.getNbDailyHours();
    case 3: return contributory.getUnit().getype();
    default: return QVariant();
    };
}


QVariant ContributoriesTableModel::headerData(
        int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal) {
        return QVariant();
    }

    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    switch (section) {
    case 0: return "Description courte";
    case 1: return "Description longue";
    case 2: return "Quantité";
    case 3: return "Unité";
    default: return QVariant();
    }
}

bool ContributoriesTableModel::setData(
        const QModelIndex &index, const QVariant &value, int role)
{
    Models::Rate r;
    if (role == Qt::EditRole) {
        switch(index.column()) {
        case 0:
            _contributories[index.row()].setDescription(value.toString());
            break;
        case 1:
            _contributories[index.row()].setLongDescription(value.toString());
            break;
        case 2:
            _contributories[index.row()].setQuantity(
                        value.toDouble()*r.getNbDailyHours());
            break;
        case 3:
            _contributories[index.row()].setUnit(Unit((TypeUnit)value.toInt()));
            break;
        default:
            Log::instance(WARNING) << "Error, in default case of "
                                      "ContributoriesTableModel::setData";
        }
    }

    return true;
}

void ContributoriesTableModel::append(const Contributory &contributory) {
    beginInsertRows(QModelIndex(),
                    _contributories.count(),
                    _contributories.count());
    _contributories.append(contributory);
    endInsertRows();
}

void ContributoriesTableModel::clear() {
    for(int i = 0 ; i < _contributories.count() ; ++i) {
        remove(i);
    }
}

void ContributoriesTableModel::remove(const int a)
{
    _contributoriesToRemoved << _contributories[a];
    _contributoriesToRemoved.last().setToRemoved(true);
    _contributories.removeAt(a);
    beginRemoveRows(QModelIndex(),
                    _contributories.count(),
                    _contributories.count());
    endRemoveRows();
}

Qt::ItemFlags ContributoriesTableModel::flags(const QModelIndex &) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}

QList<Contributory> ContributoriesTableModel::getContributories()
{
    return _contributories + _contributoriesToRemoved;
}

int ContributoriesTableModel::count() {
    return _contributories.count();
}

double ContributoriesTableModel::getSumQuantity() const
{
    double ret(0);
    for(Contributory c : _contributories) {
        ret += c.getQuantity();
    }

    return ret;
}

}
}
}
