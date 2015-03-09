#include "checkportnumber.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {


CheckPortNumber::CheckPortNumber(QWidget* w, QPushButton *btn)
    : CheckQLineEdit(w, btn)
{
}

bool CheckPortNumber::check(QString text)
{
    QRegExp numberRgx("[0-9]{0,8}");
    numberRgx.setCaseSensitivity(Qt::CaseInsensitive);
    numberRgx.setPatternSyntax(QRegExp::RegExp);

    return numberRgx.exactMatch(text);
}

}
}
}
