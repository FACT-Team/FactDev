#include "projectcontributoriestablemodel.h"
#include "utils/log.h"
namespace Gui {
namespace Widgets {
namespace WdgModels {

ProjectContributoriesTableModel::ProjectContributoriesTableModel()
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

QVariant ProjectContributoriesTableModel::data(
        const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole && role != Qt::EditRole) {
        return QVariant();
    }

    switch (index.column()) {
    case 0: return _projects[index.row()].first->getId();
    case 1: return _projects[index.row()].second.getHourlyRate();
    case 2: return _projects[index.row()].second.getDailyRate();
    default: return QVariant();
    };
}

QVariant ProjectContributoriesTableModel::headerData(
        int section, Qt::Orientation orientation, int role) const
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

bool ProjectContributoriesTableModel::setData(
        const QModelIndex &index, const QVariant &value, int role)
{
    Models::Rate r;
    if (role == Qt::EditRole) {
        switch(index.column()) {
        case 0:
            _projects[index.row()].first->hydrat(value.toInt());
            _selectedProjects << value.toInt();
            break;
        case 1:
            _projects[index.row()].second = Models::Rate(value.toDouble());
            break;
        case 2:
            r.setDailyRate(value.toDouble());
            _projects[index.row()].second = r;
            break;
        default:
            Utils::Log::instance(Utils::WARNING) <<
                "Error, in default case of "
                "ContributoriesTableModel::setData";
        }
    }

    return true;
}

Qt::ItemFlags ProjectContributoriesTableModel::flags(
        const QModelIndex &index) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void ProjectContributoriesTableModel::append()
{
    beginInsertRows(QModelIndex(), _projects.count(), _projects.count());
    _projects.append(
                QPair<Models::Project*, Models::Rate>(new Models::Project, 0));
    endInsertRows();
}

void ProjectContributoriesTableModel::append(
        QPair<Models::Project*, Models::Rate> p)
{
    beginInsertRows(QModelIndex(), _projects.count(), _projects.count());
    _projects.append(p);;
    _selectedProjects << p.first->getId();
    endInsertRows();
}

bool ProjectContributoriesTableModel::allProjectsChosen()
{
    for(QPair<Models::Project*, Models::Rate> key : _projects) {
        if(key.first->getId() == 0) {
            return false;
        }
    }
    return true;
}

void ProjectContributoriesTableModel::remove(int index) {
    beginRemoveRows(QModelIndex(), index, index);
    _selectedProjects.removeOne(_projects.at(index).first->getId());
    _projects.removeAt(index);
    endRemoveRows();
}

QPair<Models::Project *, Models::Rate>
    ProjectContributoriesTableModel::getProject(const int row)
{
    return _projects[row];
}

QList<QPair<Models::Project *, Models::Rate>>
    ProjectContributoriesTableModel::getProjects()
{
    return _projects;
}

QList<int>& ProjectContributoriesTableModel::getSelectedProjects()
{
    return _selectedProjects;
}



}
}
}

