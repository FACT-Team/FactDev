#include "projectstablemodel.h"

Gui::Widgets::WdgModels::ProjectsTableModel::ProjectsTableModel()
{

}

Gui::Widgets::WdgModels::ProjectsTableModel::~ProjectsTableModel()
{

}

int Gui::Widgets::WdgModels::ProjectsTableModel::rowCount(
        const QModelIndex &) const
{
    return _projects.count();
}

int Gui::Widgets::WdgModels::ProjectsTableModel::columnCount(
        const QModelIndex &) const
{
    return 6;
}

QVariant Gui::Widgets::WdgModels::ProjectsTableModel::data(
        const QModelIndex &index, int role) const
{
    if (    (role != Qt::DisplayRole && role != Qt::EditRole)
            || index.row() == -1)
    {
        return QVariant();
    }

    const Project &project = _projects[index.row()];
    switch (index.column()) {
    case 0: return project.getId();
    case 1: return project.getName();
    case 2: return project.getDescription();
    case 3: return project.getBeginDate();
    case 4: return project.getEndDate();
    case 5: return QString::number(project.getCost(), 'f', 2) + " €";
    default: return QVariant();
    };
}

QVariant Gui::Widgets::WdgModels::ProjectsTableModel::headerData(
        int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal) {
        return QVariant();
    }

    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    switch (section) {
    case 0: return "ID";
    case 1: return "Projet";
    case 2: return "Description";
    case 3: return "Date début";
    case 4: return "Date fin";
    case 5: return "Coût";
    default: return QVariant();
    }
}

bool Gui::Widgets::WdgModels::ProjectsTableModel::setData(
        const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole) {
        switch(index.column()) {
        case 0:
            _projects[index.row()].setId(value.toInt());
            break;
        case 1:
            _projects[index.row()].setName(value.toString());
            break;
        case 2:
            _projects[index.row()].setDescription(value.toString());
            break;
        case 3:
            _projects[index.row()].setBeginDate(value.toDate());
            break;
        case 4:
            _projects[index.row()].setEndDate(value.toDate());
            break;
        case 5:
            _projects[index.row()].setCost(value.toDouble());
            break;
        default:
            Log::instance(WARNING)
                    << "Error, in default case of ProjectsTableModel::setData";
        }
    }

    return true;
}

void Gui::Widgets::WdgModels::ProjectsTableModel::append(const Project &project)
{
    beginInsertRows(QModelIndex(), _projects.count(), _projects.count());
    _projects.append(project);
    endInsertRows();
}

void Gui::Widgets::WdgModels::ProjectsTableModel::remove(const int i)
{

}

Qt::ItemFlags Gui::Widgets::WdgModels::ProjectsTableModel::flags(
        const QModelIndex &index) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}

int Gui::Widgets::WdgModels::ProjectsTableModel::count()
{
    return _projects.count();
}

QList<Project> Gui::Widgets::WdgModels::ProjectsTableModel::getProjects() const
{
    return _projects;
}
