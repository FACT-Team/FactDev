#include "checksiretnumber.h"

CheckSiretNumber::CheckSiretNumber(QWidget* w, QPushButton *btn) : CheckQLineEdit(w, btn) {

}

bool CheckSiretNumber::check(QString text) {

    if ( text.length() != 14 ) {
        return false;
    }

    QRegExp cityRgx("[0-9]{14}");
    cityRgx.setCaseSensitivity(Qt::CaseInsensitive);
    cityRgx.setPatternSyntax(QRegExp::RegExp);

    return cityRgx.exactMatch(text);
}
