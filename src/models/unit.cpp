#include "unit.h"

namespace Models {
Unit::Unit(TypeUnit type)
{
    _type = type;
}

Unit::Unit()
{

}

QString Unit::toString(const bool plurial)
{
    if(plurial) {
        switch(_type) {
        case DAY:
            return "Jours";
            break;
        case HOUR:
            return "Heures";
            break;
        case MONTH:
            return "Mois";
            break;
        }
    } else {
        switch(_type) {
        case DAY:
            return "Jour";
            break;
        case HOUR:
            return "Heure";
            break;
        case MONTH:
            return "Mois";
            break;
        }
    }

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
