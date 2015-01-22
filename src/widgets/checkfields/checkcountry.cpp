#include "checkcountry.h"


CheckCountry::CheckCountry(QWidget *w) : CheckQLineEdit (w) {

}

bool CheckCountry::check(QString text) {
    if ( text.length() == 0 ) {
        return false;
    }

    QRegExp countrylRgx("[a-zA-Z]{2,64}");
    countrylRgx.setCaseSensitivity(Qt::CaseInsensitive);
    countrylRgx.setPatternSyntax(QRegExp::RegExp);

    return countrylRgx.exactMatch(text);
}

