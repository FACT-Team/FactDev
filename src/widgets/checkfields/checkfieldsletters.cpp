#include "checkfieldsletters.h"

CheckFieldsLetters::CheckFieldsLetters(QWidget *w, QPushButton *btn)
    : CheckUntilField (w, btn)
{
}

bool CheckFieldsLetters::check(QString text) {
    if ( text.length() == 0 ) {
        return false;
    }

    QRegExp cityRgx("[a-zA-ZÉÈÀÊËœŒæÆîïôÔëéèêà\-]{2,64}");
    cityRgx.setCaseSensitivity(Qt::CaseInsensitive);
    cityRgx.setPatternSyntax(QRegExp::RegExp);

    return cityRgx.exactMatch(text);
}
