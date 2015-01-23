#include "checkpostalcode.h"

CheckPostalCode::CheckPostalCode(QWidget* w, QPushButton* btn ) : CheckQLineEdit (w, btn) {

}


bool CheckPostalCode::check(QString text) {
    QRegExp postalCodeRgx("[0-9]{5}");
    postalCodeRgx.setCaseSensitivity(Qt::CaseInsensitive);
    postalCodeRgx.setPatternSyntax(QRegExp::RegExp);

    return postalCodeRgx.exactMatch(text);
}
