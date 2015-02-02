#include "checkqlineedit.h"
#include "checkphone.h"
#include <QDebug>
CheckPhone::CheckPhone(QWidget *w, QPushButton* btn) : CheckUntilField(w, btn) {
    _country = "";
}

bool CheckPhone::check(QString text)
{
    bool isChecked = true;

    if ( text.length() == 0 ) {
        isChecked = false;
    }

    if (this->getCountry() == "FRANCE") {
        text = text.replace(" ", "");
        text = text.replace(".", "");
        text = text.replace("+33","0");
        text = text.replace("(","");
        text = text.replace(")","");
        if (text[0]=='0' && text[1]=='0' && text[2]=='3' && text[3]=='3') {
            QString buff = text;
            text = "0";
            for (int i=0; i < 9; i++) {
                text += ""+buff[i+4];
            }
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


