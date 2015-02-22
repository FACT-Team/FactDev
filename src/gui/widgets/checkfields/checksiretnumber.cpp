#include "checksiretnumber.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {

CheckSiretNumber::CheckSiretNumber(QWidget* w, QPushButton *btn) : CheckQLineEdit(w, btn) {

}

bool CheckSiretNumber::check(QString text) {

    if ( text.length() != 14 ) {
        return false;
    }

    text.replace(" ","");
    text.replace("-","");
    QRegExp siretRgx("[0-9]{14}");
    siretRgx.setCaseSensitivity(Qt::CaseInsensitive);
    siretRgx.setPatternSyntax(QRegExp::RegExp);

    return siretRgx.exactMatch(text);
}

}
}
}
