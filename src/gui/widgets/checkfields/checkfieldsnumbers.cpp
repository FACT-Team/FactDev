#include "checkfieldsnumbers.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {

CheckFieldsNumbers::CheckFieldsNumbers(QWidget* w, QPushButton *btn)
    : CheckUntilField(w, btn)
{
}

bool CheckFieldsNumbers::check(QString text)
{
    QRegExp numberRgx("[0-9]{1,8}");
    numberRgx.setCaseSensitivity(Qt::CaseInsensitive);
    numberRgx.setPatternSyntax(QRegExp::RegExp);

    return numberRgx.exactMatch(text);
}


}
}
}
