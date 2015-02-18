#ifndef BILLINGSTABLEMODEL_H
#define BILLINGSTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>

#include "models/billing.h"
#include "utils/log.h"

using namespace Models;
using namespace Utils;

namespace Gui {
namespace Widgets {
namespace WdgModels {

/**
 * @author Florent Berbie
 * @brief The BillingsTableModel class for a Billing table
 * @see Billing
 */
class BillingsTableModel : public QAbstractTableModel
{
public:
    /**
     * @brief BillingsTableModel::BillingsTableModel Construct a
     * BillingsTableModel
     * @param parent Parent widget
     */
    BillingsTableModel();
    ~BillingsTableModel();

    /**
     * @brief BillingsTableModel::rowCount Number of billings row
     * @return The number of billings
     */
    int rowCount(const QModelIndex &) const;

    /**
     * @brief BillingsTableModel::columnCount Number of column of a Billing
     * @return  The number of column
     */
    int columnCount(const QModelIndex &) const;

    /**
     * @brief BillingsTableModel::data Obtains data of a specify cell
     * @param index The cell who we want data
     * @param role The role of set
     * @return The data of cell
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    /**
     * @brief BillingsTableModel::headerData Obtains header title of table
     * @param section The number of column
     * @param orientation The table orientation
     * @param role
     * @return The Title header of column
     */
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

    /**
      * @brief BillingsTableModel::setData Change data of a cell
      * @param index The cell to change data
      * @param value The new value
      * @param role The role of cell
      * @return True if we could edit
      */
     bool setData(const QModelIndex & index, const QVariant & value,
                  int role = Qt::EditRole);

     /**
     * @brief BillingsTableModel::append Add a new line in table
     * @param Billing The new Billing
     */
    void append(const Billing &billing);

    /**
     * @brief BillingsTableModel::remove Remove a line
     * @param i The number of line to remove
     */
    void remove(const int i);

    /**
     * @brief BillingsTableModel::flags Differents table flags
     * @param index The cell who we want to know flags
     * @return Flags
     */
    Qt::ItemFlags flags(const QModelIndex & index) const ;

    /**
     * @brief BillingsTableModel::count Number of billings in table
     * @return The number of billings
     */
    int count();

    /**
     * @brief BillingsTableModel::getbillings Return the list of billings
     * @return list of billings
     */
    QList<Billing> getBillings() const;

private:
    QList<Billing> _billings;   //!< billings list
};
}
}
}
#endif // BILLINGSTABLEMODEL_H
