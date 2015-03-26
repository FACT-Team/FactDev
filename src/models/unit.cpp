#include "unit.h"

namespace Models {
Unit::Unit(TypeUnit type)
{
    _type = type;
}

Unit::Unit()
{

}

QString Unit::toString()
{
    return _type == DAY ? "Jour" : "Heure";
}

TypeUnit Unit::getype() const
{
    return _type;
}

void Unit::setType(const TypeUnit &type)
{
    _type = type;
}

bool Unit::operator ==(const Unit &u)
{
    return _type == u.getype();
}

bool Unit::operator !=(const Unit &u)
{
    return _type != u.getype();
}


}
