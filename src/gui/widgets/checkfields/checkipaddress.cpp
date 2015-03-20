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
    QRegExp ipAddessRgx("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}");
    ipAddessRgx.setCaseSensitivity(Qt::CaseInsensitive);
    ipAddessRgx.setPatternSyntax(QRegExp::RegExp);

    QRegExp domainName("\\b[A-Z0-9._%+-]+\\.[A-Z]{2,4}\\b");
    domainName.setCaseSensitivity(Qt::CaseInsensitive);
    domainName.setPatternSyntax(QRegExp::RegExp);

    return ipAddessRgx.exactMatch(text) || domainName.exactMatch(text);
}

}
}
}
