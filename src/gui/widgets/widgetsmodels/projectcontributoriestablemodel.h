#ifndef PROJECTCONTRIBUTORIESTABLEMODEL_H
#define PROJECTCONTRIBUTORIESTABLEMODEL_H
#include <QAbstractTableModel>
#include <QSet>
#include <QPair>

#include "models/project.h"
#include "models/rate.h"

namespace Gui {
namespace Widgets {
namespace WdgModels {

/**
 * @author Antoine de Roquemaurel
 * @brief The ProjectContributoriesTableModel class Table model of
 * contributories linked to projets
 */
class ProjectContributoriesTableModel : public QAbstractTableModel
{
public:
    /**
     * @brief ProjectContributoriesTableModel::ProjectContributoriesTableModel
     *  Construct a ProjectContributoriesTableModel
     * @param parent Parent widget
     */
    ProjectContributoriesTableModel(QObject* parent = 0);

    /**
     * @brief ProjectContributoriesTableModel::rowCount Number of contributories
     *  row
     * @return The number of contributories
     */
    int rowCount(const QModelIndex &) const;

    /**
     * @brief ProjectContributoriesTableModel::columnCount Number of column of a
     *  contributory
     * @return  The number of column
     */
    int columnCount(const QModelIndex &) const;

    /**
     * @brief ProjectContributoriesTableModel::data Obtains data of a specify
     *  cell
     * @param index The cell who we want data
     * @param role The role of set
     * @return The data of cell
     */
    QVariant data(const QModelIndex &index, int role) const;

    /**
     * @brief ProjectContributoriesTableModel::headerData Obtains header title
     * of table
     * @param section The number of column
     * @param orientation The table orientation
     * @param role
     * @return The Title header of column
     */
    QVariant headerData(
            int section, Qt::Orientation orientation, int role) const;

    /**
        * @brief ProjectContributoriesTableModel::setData Change data of a cell
        * @param index The cell to change data
        * @param value The new value
        * @param role THe role of cell
        * @return True if we could edit
        */
     bool setData(const QModelIndex & index,
                  const QVariant & value,
                  int role = Qt::EditRole);

     /**
      * @brief ProjectContributoriesTableModel::flags Differents table flags
      * @param index The cell who we want to know flags
      * @return Flags
      */
     Qt::ItemFlags flags(const QModelIndex & index) const ;

     /**
     * @brief ProjectContributoriesTableModel::append Add a new rate <i>p</i> to
     *  a Project
     * @param p
     */
    void append(QPair<Models::Project *, Models::Rate> p);

    /**
     * @brief ProjectContributoriesTableModel::append Add the current element to
     *  the list
     */
    void append();

    /**
     * @brief ProjectContributoriesTableModel::allProjectsChose Return TRUE if
     * all projects have been selected else FALSE
     * @return boolean All projects selected
     */
    bool allProjectsChosen();

    /**
     * @brief ProjectContributoriesTableModel::getSelectedProjects Return the
     * list of the Project id which are selected
     * @return List of ID Project
     */
    QList<int> &getSelectedProjects();

    /**
     * @brief ProjectContributoriesTableModel::remove Remove the element to the
     * <i>index</i>
     * @param index Index of the element to remove
     */
    void remove(int index);

    /**
     * @brief ProjectContributoriesTableModel::getProject Return the project
     * and it rate linked which correspond to the <i>row</i>
     * @param row Row of the project to get
     * @return a Project and it rate
     */
    QPair<Models::Project*, Models::Rate> getProject(const int row);

    /**
     * @brief ProjectContributoriesTableModel::getProjects Return a list of the
     * set of projects and their rates linked
     * @return List of Projects and Rates linked
     */
    QList<QPair<Models::Project*, Models::Rate> > getProjects(void);

private:
    //!< List of Projects ant the rate linked to each project
    QList<QPair<Models::Project*, Models::Rate> > _projects;
    QList<int> _selectedProjects;   //!< List of ID Projects selected

};

}
}
}

#endif // PROJECTCONTRIBUTORIESTABLEMODEL_H
