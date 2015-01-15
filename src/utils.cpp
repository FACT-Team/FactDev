#include "utils.h"

QString Utils::firstLetterToUpper(QString s)
{
    return s.replace(0, 1, s[0].toUpper());
}
