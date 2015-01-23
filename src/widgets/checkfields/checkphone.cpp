#include "checkqlineedit.h"
#include "checkphone.h"

CheckPhone::CheckPhone(QWidget *w, QPushButton* btn) : CheckQLineEdit(w, btn) {

}


bool CheckPhone::check(QString text) {
    if ( text.length() == 0 ) {
        return false;
    }

    //QRegExp phonelRgx("^\\+\\d{1,2}\\([089]\\)\\d{2,5}\\-\\d+$");

    QRegExp phonelRgx("[0-9]{10,14}");
    phonelRgx.setCaseSensitivity(Qt::CaseInsensitive);
    phonelRgx.setPatternSyntax(QRegExp::RegExp);

    return phonelRgx.exactMatch(text);
}
