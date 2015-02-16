#include "customerstablemodel.h"

Gui::Widgets::WdgModels::CustomersTableModel::CustomersTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

int Gui::Widgets::WdgModels::CustomersTableModel::rowCount(const QModelIndex &) const
{
    return _customers.count();
}

int Gui::Widgets::WdgModels::CustomersTableModel::columnCount(const QModelIndex &) const
{
    return 6;
}

QVariant Gui::Widgets::WdgModels::CustomersTableModel::data(
        const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole && role != Qt::EditRole) {
        return QVariant();
    }
    const Customer &customer = _customers[index.row()];
    switch (index.column()) {
    case 0: return customer.getId();
    case 1: return customer.getCompany();
    case 2: return customer.getLastnameReferent();
    case 3: return customer.getFirstnameReferent();
    case 4: return customer.getPhone();
    case 5: return customer.getEmail();
    default: return QVariant();
    };
}

QVariant Gui::Widgets::WdgModels::CustomersTableModel::headerData(int section,
    Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal) {
        return QVariant();
    }

    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    switch (section) {
    case 0: return "ID";
    case 1: return "Société";
    case 2: return "NOM";
    case 3: return "Prénom";
    case 4: return "Téléphone";
    case 5: return "E-mail";
    default: return QVariant();
    }
}

bool Gui::Widgets::WdgModels::CustomersTableModel::setData(
        const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole) {
        switch(index.column()) {
        case 0:
            _customers[index.row()].setId(new Customer(value.toInt()));
            break;
        case 1:
            _customers[index.row()].setCompany(value.toString());
            break;
        case 2:
            _customers[index.row()].setLastnameReferent(value.toString());
            break;
        case 3:
            _customers[index.row()].setFirstnameReferent(value.toString());
            break;
        case 4:
            _customers[index.row()].setPhone(value.toString());
            break;
        case 5:
            _customers[index.row()].setEmail(value.toString());
            break;
        default:
            Log::instance(WARNING) << "Error, in default case of CustomersTableModel::setData";
        }
    }

    return true;
}

void Gui::Widgets::WdgModels::CustomersTableModel::append(const Contributory &contributory)
{

}

void Gui::Widgets::WdgModels::CustomersTableModel::remove(const int i)
{

}

Qt::ItemFlags Gui::Widgets::WdgModels::CustomersTableModel::flags(const QModelIndex &index) const
{

}

QList<Customer> Gui::Widgets::WdgModels::CustomersTableModel::customers() const
{

}
QList<Customer> CustomersTableModel::getCustomers() const
{
    return _customers;
}
