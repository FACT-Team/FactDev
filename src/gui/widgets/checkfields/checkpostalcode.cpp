#include "checkpostalcode.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {


CheckPostalCode::CheckPostalCode(QWidget* w, QPushButton* btn ) : CheckUntilField (w, btn) {

}

bool CheckPostalCode::check(QString text)
{
    bool isChecked = true;

    if ( text.length() == 0 ) {
        isChecked = false;
    }

    if (getCountry() == "FRANCE") {
        text = text.replace(" ", "");
        text = text.replace(".", "");
        QRegExp postalCodeRgx("[0-9]{5,5}");

        postalCodeRgx.setCaseSensitivity(Qt::CaseInsensitive);
        postalCodeRgx.setPatternSyntax(QRegExp::RegExp);
        isChecked = postalCodeRgx.exactMatch(text);
    }

    return isChecked;
}

QString CheckPostalCode::getCountry() const
{
    return _country;
}

void CheckPostalCode::setCountry(const QString &country)
{
    _country = country.toUpper();
}

}
}
}
