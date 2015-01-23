#include "checkcity.h"

CheckCity::CheckCity(QWidget *w, QPushButton* btn) : CheckFieldsLetters (w, btn) {

}

//bool CheckCity::check(QString text) {

//    if ( text.length() == 0 ) {
//        return false;
//    }

//    QRegExp cityRgx("[a-zA-ZÉÈÀÊËœŒæÆîïôÔëéèêà\-]{2,64}");
//    cityRgx.setCaseSensitivity(Qt::CaseInsensitive);
//    cityRgx.setPatternSyntax(QRegExp::RegExp);

//    return cityRgx.exactMatch(text);
//}
