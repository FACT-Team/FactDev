#ifndef PROJECTCONTRIBUTORIESTABLEMODEL_H
#define PROJECTCONTRIBUTORIESTABLEMODEL_H
#include <QAbstractTableModel>
#include <QSet>
#include <QPair>

#include "models/project.h"

namespace Gui {
namespace Widgets {
namespace WdgModels {


class ProjectContributoriesTableModel : public QAbstractTableModel
{
public:
    /**
     * @brief ContributoriesTableModel Construct a ContributoriesTableModel
     * @param parent Parent widget
     */
    ProjectContributoriesTableModel(QObject* parent = 0);

    /**
     * @brief rowCount Number of contributories row
     * @return The number of contributories
     */
    int rowCount(const QModelIndex &) const;

    /**
     * @brief columnCount Number of column of a contributory
     * @return  The number of column
     */
    int columnCount(const QModelIndex &) const;

    /**
     * @brief data Obtains data of a specify cell
     * @param index The cell who we want data
     * @param role The role of set
     * @return The data of cell
     */
    QVariant data(const QModelIndex &index, int role) const;

    /**
     * @brief headerData Obtains header title of table
     * @param section The number of column
     * @param orientation The table orientation
     * @param role
     * @return The Title header of column
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    /**
      * @brief setData Change data of a cell
      * @param index The cell to change data
      * @param value The new value
      * @param role THe role of cell
      * @return True if we could edit
      */
     bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);

     /**
      * @brief flags Differents table flags
      * @param index The cell who we want to know flags
      * @return Flags
      */
     Qt::ItemFlags flags(const QModelIndex & index) const ;

    void append();

private:
     QList<QPair<Models::Project*, double> > _projects;
};

}
}
}

#endif // PROJECTCONTRIBUTORIESTABLEMODEL_H
