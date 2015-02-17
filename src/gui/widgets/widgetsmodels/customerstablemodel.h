#ifndef CUSTOMERSTABLEMODEL_H
#define CUSTOMERSTABLEMODEL_H
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
 * @author Florent Berbie
 * @brief The CustomersTableModel class for a customer table
 * @see Customer
 */
class CustomersTableModel : public QAbstractTableModel
{
public:
    /**
     * @brief CustomersTableModel::CustomersTableModel Construct a
     * CustomersTableModel
     * @param parent Parent widget
     */
    CustomersTableModel(QObject* parent = 0);

    /**
     * @brief CustomersTableModel::rowCount Number of customers row
     * @return The number of customers
     */
    int rowCount(const QModelIndex &) const;

    /**
     * @brief CustomersTableModel::columnCount Number of column of a customer
     * @return  The number of column
     */
    int columnCount(const QModelIndex &) const;

    /**
     * @brief CustomersTableModel::data Obtains data of a specify cell
     * @param index The cell who we want data
     * @param role The role of set
     * @return The data of cell
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    /**
     * @brief CustomersTableModel::headerData Obtains header title of table
     * @param section The number of column
     * @param orientation The table orientation
     * @param role
     * @return The Title header of column
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    /**
      * @brief CustomersTableModel::setData Change data of a cell
      * @param index The cell to change data
      * @param value The new value
      * @param role The role of cell
      * @return True if we could edit
      */
     bool setData(const QModelIndex & index, const QVariant & value,
                  int role = Qt::EditRole);

     /**
     * @brief CustomersTableModel::append Add a new line in table
     * @param Customer The new customer
     */
    void append(const Customer &customer);

    /**
     * @brief CustomersTableModel::remove Remove a line
     * @param i The number of line to remove
     */
    void remove(const int i);

    /**
     * @brief CustomersTableModel::flags Differents table flags
     * @param index The cell who we want to know flags
     * @return Flags
     */
    Qt::ItemFlags flags(const QModelIndex & index) const ;

    /**
     * @brief CustomersTableModel::count Number of customers in table
     * @return The number of customers
     */
    int count();

    /**
     * @brief CustomersTableModel::getCustomers Return the list of customers
     * @return list of Customers
     */
    QList<Customer> getCustomers() const;

private:
    QList<Customer> _customers; //!< contributories list
};
}
}
}
#endif // CUSTOMERSTABLEMODEL_H
