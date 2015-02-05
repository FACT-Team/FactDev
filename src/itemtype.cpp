#include "itemtype.h"
ItemType::ItemType(int type, QString name)
{
    _type = type;
    _name = name;
}
QString ItemType::getName() const
{
    return _name;
}

void ItemType::setName(const QString &name)
{
    _name = name;
}

IDatabaseModel* ItemType::getModel(int id) {
    IDatabaseModel* ret;

    switch(_type) {
    case ItemType::BILLING:
    case ItemType::QUOTE:
        ret = new Models::Billing(id);
        break;
    case ItemType::CUSTOMER:
        ret = new Customer(id);
        break;
    case ItemType::PROJECT:
        ret = new Project(id);
        break;
    default:
        Log::instance(WARNING) << "MainWindow::removeItem bad item type";
    }

    return ret;
}
int ItemType::getType() const
{
    return _type;
}

void ItemType::setType(int type)
{
    _type = type;
}


