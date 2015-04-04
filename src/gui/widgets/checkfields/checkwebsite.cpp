#include "checkwebsite.h"
namespace Gui {
namespace Widgets {
namespace CheckFields {

CheckWebsite::CheckWebsite(QWidget* w, QPushButton *btn)
    : CheckValidField(w, btn)
{
}

bool CheckWebsite::check(QString text)
{
    QRegExp ipAddessRgx("http://[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}"); // Ip address
    ipAddessRgx.setCaseSensitivity(Qt::CaseInsensitive);
    ipAddessRgx.setPatternSyntax(QRegExp::RegExp);

    QRegExp domainName("http://\\b[A-Z0-9._%+-]+\\.[A-Z]{2,4}\\b");
    domainName.setCaseSensitivity(Qt::CaseInsensitive);
    domainName.setPatternSyntax(QRegExp::RegExp);

    QRegExp wwwName("www\\.\\b[A-Z0-9._%+-]+\\.[A-Z]{2,4}\\b");
    wwwName.setCaseSensitivity(Qt::CaseInsensitive);
    wwwName.setPatternSyntax(QRegExp::RegExp);

    return ipAddessRgx.exactMatch(text) || domainName.exactMatch(text) || wwwName.exactMatch(text) || text.isEmpty();
}

}
}
}
