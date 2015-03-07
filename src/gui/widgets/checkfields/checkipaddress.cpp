#include "checkipaddress.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {


CheckIpAddress::CheckIpAddress(QWidget* w, QPushButton *btn)
    : CheckUntilField(w, btn)
{
}

bool CheckIpAddress::check(QString text)
{
    QRegExp numberRgx("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}");
    numberRgx.setCaseSensitivity(Qt::CaseInsensitive);
    numberRgx.setPatternSyntax(QRegExp::RegExp);

    return numberRgx.exactMatch(text);
}

}
}
}
