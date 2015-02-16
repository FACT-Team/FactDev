#include "projectcontributoriestablemodel.h"
#include <QDebug>
#include "utils/log.h"
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
    if (role != Qt::DisplayRole && role != Qt::EditRole) {
        return QVariant();
    }
    switch (index.column()) {
    case 0: return _projects[index.row()].first->getId();
    case 1: return _projects[index.row()].second;
    case 2: return _projects[index.row()].second;
    default: return QVariant();
    };
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
    if (role == Qt::EditRole) {
        switch(index.column()) {
        case 0:
            delete _projects[index.row()].first;
            _projects[index.row()].first = new Models::Project(value.toInt());
            break;
        case 1:
            _projects[index.row()].second = value.toDouble();
            break;
        case 2:
            break;
        default:
        Utils::Log::instance(Utils::WARNING) << "Error, in default case of ContributoriesTableModel::setData";
        }
    }

    return true;
}

Qt::ItemFlags ProjectContributoriesTableModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void ProjectContributoriesTableModel::append()
{
    beginInsertRows(QModelIndex(), _projects.count(), _projects.count());
    _projects.append(QPair<Models::Project*, double>(new Models::Project, 0));
    endInsertRows();
}

}
}
}

