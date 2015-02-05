#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <QString>
#include "models/idatabasemodel.h"
#include "models/billing.h"
#include "models/customer.h"
#include "models/project.h"

#include "log.h"

/**
 * @brief The ItemType class Item type model
 */
class ItemType
{
public:
    static const int CUSTOMER = 0;  //!< constant value assigned to Customer
    static const int PROJECT = 1;   //!< constant value assigned to Project
    static const int BILLING = 2;   //!< constant value assigned to Billing
    static const int QUOTE = 3;     //!< constant value assigned to Quote

    /**
     * @brief ItemType::ItemType Construct an Item type
     * @param type Type of the item
     * @param name Name of the item
     */
    ItemType(int type, QString name);

    /**
     * @brief ItemType::getName Get item name
     * @return item name
     */
    QString getName() const;

    /**
     * @brief ItemType::getModel Get the databasemodele of the <b>ItemType</b>
     * according to this identity <i>id</i>
     * @param id Item type identity
     * @return database model
     */
    Models::IDatabaseModel* getModel(int id);

    /**
     * @brief ItemType::setName Modify the item name
     * @param name New Item name
     */
    void setName(const QString &name);

    /**
     * @brief ItemType::getType Get the type of the current item
     * @return type of the current item
     */
    int getType() const;    
    /**
     * @brief ItemType::setType Modify the type of the current item
     * @param type New item type
     */
    void setType(int type);

private:
    QString _name;  //!< Name of the type item
    int _type;      //!< Type of the item
};

#endif // ITEMTYPE_H
