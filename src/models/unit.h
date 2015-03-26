#ifndef UNIT_H
#define UNIT_H
#include <QString>

namespace Models {
/**
 * @brief The TypeUnit enum Type Unit : hour or days.
 */
enum TypeUnit{HOUR, DAY};

/**
 * @brief The Unit class An unity for billing calculs
 */
class Unit
{
public:
    /**
     * @brief Unit Construct an unit with init type
     * @param type The unit Type;
     */
    Unit(TypeUnit type);

    /**
     * @brief Unit Construct an unit
     */
    Unit();

    /**
     * @brief toString Return String for unit type.
     * @return The unit in String
     */
    QString toString();

    /**
     * @brief getype The unit Type
     * @return The unit Type
     */
    TypeUnit getype() const;

    /**
     * @brief setType Change the unit Type
     * @param type The new unit type.
     */
    void setType(const TypeUnit &type);

    /**
     * @brief operator == define the operator "==" to compare two
     * <b>Unit</b>
     * @param c the <b>Unit</b> to compare with the current
     * <b>Contributory</b>
     * @return true if the <b>Unit</b> are equals else false
     */
    bool operator ==(const Unit &u);

    /**
     * @brief operator != define the operator "!=" to compare two
     * <b>Unit</b>
     * @param c the <b>Unit</b> to compare with the current
     * <b>Contributory</b>
     * @return true if the <b>Unit</b> are different else false
     */
    bool operator !=(const Unit &u);

private:
    TypeUnit _type; //!< The unit type.
};
}
#endif // UNIT_H
