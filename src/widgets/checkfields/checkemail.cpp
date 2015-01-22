#include <QDebug>
#include "checkemail.h"


CheckEmail::CheckEmail(QWidget *w) : CheckQLineEdit(w)
{

}

bool CheckEmail::check(QString text)
{
    if ( text.length() == 0 ) {
        return false;
    }

    QRegExp emailRgx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    emailRgx.setCaseSensitivity(Qt::CaseInsensitive);
    emailRgx.setPatternSyntax(QRegExp::RegExp);

    return emailRgx.exactMatch(text);
}
