#include "checkcity.h"

CheckCity::CheckCity(QWidget *w) : CheckQLineEdit (w) {

}

bool CheckCity::check(QString text) {

    if ( text.length() == 0 ) {
        return false;
    }

    QRegExp cityRgx("[a-zA-Z]{2,64}");
    cityRgx.setCaseSensitivity(Qt::CaseInsensitive);
    cityRgx.setPatternSyntax(QRegExp::RegExp);

    return cityRgx.exactMatch(text);
}
