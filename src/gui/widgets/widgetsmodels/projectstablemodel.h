#ifndef PROJECTSTABLEMODEL_H
#define PROJECTSTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>

#include "models/project.h"
#include "utils/log.h"

using namespace Models;
using namespace Utils;

namespace Gui {
namespace Widgets {
namespace WdgModels {

/**
 * @author Florent Berbie
 * @brief The ProjectsTableModel class for a Project table
 * @see Project
 */
class ProjectsTableModel : public QAbstractTableModel
{
public:
    /**
     * @brief ProjectsTableModel::ProjectsTableModel Construct a
     * ProjectsTableModel
     * @param parent Parent widget
     */
    ProjectsTableModel();
    ~ProjectsTableModel();

    /**
     * @brief ProjectsTableModel::rowCount Number of projects row
     * @return The number of projects
     */
    int rowCount(const QModelIndex &) const;

    /**
     * @brief ProjectsTableModel::columnCount Number of column of a Project
     * @return  The number of column
     */
    int columnCount(const QModelIndex &) const;

    /**
     * @brief ProjectsTableModel::data Obtains data of a specify cell
     * @param index The cell who we want data
     * @param role The role of set
     * @return The data of cell
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    /**
     * @brief ProjectsTableModel::headerData Obtains header title of table
     * @param section The number of column
     * @param orientation The table orientation
     * @param role
     * @return The Title header of column
     */
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

    /**
      * @brief ProjectsTableModel::setData Change data of a cell
      * @param index The cell to change data
      * @param value The new value
      * @param role The role of cell
      * @return True if we could edit
      */
     bool setData(const QModelIndex & index, const QVariant & value,
                  int role = Qt::EditRole);

     /**
     * @brief ProjectsTableModel::append Add a new line in table
     * @param Project The new Project
     */
    void append(const Project &project);

    /**
     * @brief ProjectsTableModel::remove Remove a line
     * @param i The number of line to remove
     */
    void remove(const int i);

    /**
     * @brief ProjectsTableModel::flags Differents table flags
     * @param index The cell who we want to know flags
     * @return Flags
     */
    Qt::ItemFlags flags(const QModelIndex & index) const ;

    /**
     * @brief ProjectsTableModel::count Number of projects in table
     * @return The number of projects
     */
    int count();

    /**
     * @brief ProjectsTableModel::getProjects Return the list of projects
     * @return list of projects
     */
    QList<Project> getProjects() const;

private:
    QList<Project> _projects;   //!< projects list
};
}
}
}
#endif // PROJECTSTABLEMODEL_H
