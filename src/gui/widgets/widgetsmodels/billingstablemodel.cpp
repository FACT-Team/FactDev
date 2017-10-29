#include "billingstablemodel.h"

Gui::Widgets::WdgModels::BillingsTableModel::BillingsTableModel()
{

}

Gui::Widgets::WdgModels::BillingsTableModel::~BillingsTableModel()
{

}

int Gui::Widgets::WdgModels::BillingsTableModel::rowCount(
        const QModelIndex &) const
{
    return _billings.count();
}

int Gui::Widgets::WdgModels::BillingsTableModel::columnCount(
        const QModelIndex &) const
{
    return 7;
}

QVariant Gui::Widgets::WdgModels::BillingsTableModel::data(
        const QModelIndex &index, int role) const
{
    if ((role != Qt::DisplayRole && role != Qt::EditRole && role != Qt::DecorationRole) || index.row() == -1) {
        return QVariant();
    }

    const Billing &billing = _billings[index.row()];
    switch (index.column()) {
    case 0: return billing.getId();
    case 1: return QImage(
                    ":icons/"
                    + QString((billing.isBilling() ? "bill"  : "quote"))
                    ).scaled(25,25);
    case 2: return billing.getNumber();
    case 3: return billing.getTitle();
    case 4: return billing.getDescription();
    case 5: return billing.getDate();
    case 6:
        return billing.isPaid() ? QImage(
                                      ":/icons/img/img32/ok_pay.png"
                                      ).scaled(30,30) :
                                  QVariant();
    default: return QVariant();
    };
}

QVariant Gui::Widgets::WdgModels::BillingsTableModel::headerData(
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
    case 1: return "";
    case 2: return "N°";
    case 3: return "Titre";
    case 4: return "Description";
    case 5: return "Date";
    case 6: return "Payée";
    default: return QVariant();
    }
}

bool Gui::Widgets::WdgModels::BillingsTableModel::setData(
        const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole) {
        switch(index.column()) {
        case 0:
            _billings[index.row()].setId(value.toInt());
            break;
        case 2:
            _billings[index.row()].setTitle(value.toString());
            break;
        case 3:
            _billings[index.row()].setNumber(value.toInt());
            break;
        case 4:
            _billings[index.row()].setDate(value.toDate());
            break;
        default:
            Log::instance(WARNING)
                    << "Error, in default case of BillingsTableModel::setData";
        }
    }

    return true;
}

void Gui::Widgets::WdgModels::BillingsTableModel::append(const Billing &billing)
{
    beginInsertRows(QModelIndex(), _billings.count(), _billings.count());
    _billings.append(billing);
    endInsertRows();
}

Qt::ItemFlags Gui::Widgets::WdgModels::BillingsTableModel::flags(
        const QModelIndex &index) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}

int Gui::Widgets::WdgModels::BillingsTableModel::count()
{
    return _billings.count();
}

QList<Billing> Gui::Widgets::WdgModels::BillingsTableModel::getBillings() const
{
    return _billings;
}
