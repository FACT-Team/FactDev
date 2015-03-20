#include "checkqlineedit.h"
#include "checkphone.h"
#include <QStringRef>

namespace Gui {
namespace Widgets {
namespace CheckFields {

CheckPhone::CheckPhone(QWidget *w, QPushButton* btn) : CheckUntilField(w, btn) {
    _country = "";
}

bool CheckPhone::check(QString text)
{
    bool isChecked = true;

    if ( text.length() == 0 ) {
        isChecked = false;
    }

    if (getCountry() == "FRANCE") {
        text = text.replace(" ", "");
        text = text.replace(".", "");
        text = text.replace("+33","0");
        text = text.replace("(","");
        text = text.replace(")","");

        if (text.mid(0,4) == "0033") {
            text = "0" + text.right(9);
        }

        QRegExp phoneRgx("[0-9\\(\\)\\+\\s\\-\\.]{10,10}");
        phoneRgx.setCaseSensitivity(Qt::CaseInsensitive);
        phoneRgx.setPatternSyntax(QRegExp::RegExp);
        isChecked = phoneRgx.exactMatch(text);
    }

    return isChecked;
}

QString CheckPhone::getCountry() const
{
    return _country;
}

void CheckPhone::setCountry(const QString &country)
{
    _country = country.toUpper();
}


}
}
}
