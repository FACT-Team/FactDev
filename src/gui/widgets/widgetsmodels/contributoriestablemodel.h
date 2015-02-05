#ifndef CONTRIBUTORIESTABLEMODEL_H
#define CONTRIBUTORIESTABLEMODEL_H
#include <QObject>
#include <QAbstractTableModel>

#include "models/contributory.h"

#include "utils/log.h"

using namespace Models;
using namespace Utils;

namespace Gui {
namespace Widgets {
namespace WdgModels {

/**
 * @author Antoine de Roquemaurel
 * @brief The ContributoriesTableModel class for a custom table for contributories widget
 * @see Contributory
 */
class ContributoriesTableModel : public QAbstractTableModel
{
public:
    /**
     * @brief ContributoriesTableModel Construct a ContributoriesTableModel
     * @param parent Parent widget
     */
    ContributoriesTableModel(QObject* parent = 0);

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
     * @brief append Add a new line in table
     * @param contributory The new contributory
     */
    void append(const Contributory & contributory);

    /**
     * @brief remove Remove a line
     * @param i The number of line to remove
     */
    void remove(const int i);

    /**
     * @brief flags Differents table flags
     * @param index The cell who we want to know flags
     * @return Flags
     */
    Qt::ItemFlags flags(const QModelIndex & index) const ;

    /**
     * @brief getContributories Get all contributories of table
     * @return The contributory list
     */
    QList<Contributory> getContributories();

    /**
     * @brief count Number of contributories in table
     * @return The number of contributories
     */
    int count();
private:
    QList<Contributory> _contributories; //!< contributories list
    QList<Contributory> _contributoriesToRemoved; //!< Contributories to removed
};
}
}
}

#endif // CONTRIBUTORIESTABLEMODEL_H
