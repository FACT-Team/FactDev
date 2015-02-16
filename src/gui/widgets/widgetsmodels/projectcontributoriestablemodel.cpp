#include "projectcontributoriestablemodel.h"

namespace Gui {
namespace Widgets {
namespace WdgModels {

ProjectContributoriesTableModel::ProjectContributoriesTableModel(QObject *parent)
{

}

int ProjectContributoriesTableModel::rowCount(const QModelIndex &) const
{
    return _projects.count();
}

int ProjectContributoriesTableModel::columnCount(const QModelIndex &) const
{
    return 3;
}

QVariant ProjectContributoriesTableModel::data(const QModelIndex &index, int role) const
{

}

QVariant ProjectContributoriesTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal) {
        return QVariant();
    }

    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    switch (section) {
    case 0: return "Projet";
    case 1: return "Tarif horaire";
    case 2: return "Tarif Journalier";
    default: return QVariant();
    }

}

bool ProjectContributoriesTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

Qt::ItemFlags ProjectContributoriesTableModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}

}
}
}

