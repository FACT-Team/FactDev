#include "checkfieldsletters.h"

CheckFieldsLetters::CheckFieldsLetters(QWidget *w, QPushButton *btn)
    : CheckUntilField (w, btn)
{
}

bool CheckFieldsLetters::check(QString text) {
    if ( text.length() == 0 ) {
        return false;
    }

    QRegExp txtRgx("[a-zA-ZÉÈÀÊËœŒæÆîïôÔëéèêà\\-\\s\\'\\,\\;\\(\\)\\.\\/\\\\]{2,64}");
    txtRgx.setCaseSensitivity(Qt::CaseInsensitive);
    txtRgx.setPatternSyntax(QRegExp::RegExp);

    return txtRgx.exactMatch(text);
}
