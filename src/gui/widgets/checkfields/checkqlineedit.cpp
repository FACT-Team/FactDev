#include "checkqlineedit.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {

CheckQLineEdit::CheckQLineEdit(QWidget *parent, QPushButton* btn) : QLineEdit(parent)
{
    _btnValid = btn;
}

void CheckQLineEdit::fieldTextChanged(const QString &text) {

    if (check(text)) {
        displayCheckValidFieldIcon();
        if (_btnValid != NULL) {
            _btnValid->setEnabled(true);
        }
    } else {
        displayCheckNoValidFieldIcon();
        if (_btnValid != NULL) {
            _btnValid->setEnabled(false);
        }
    }
}

void CheckQLineEdit::displayCheckValidFieldIcon()
{
    QString styleValid =
            "background: url(:/icons/img/img20/yes20.png);"
            "background-position: right;"
            "background-repeat: no-repeat;     "
            "border-radius: 0px;"
            "height: 22px;"
            "border: 1px solid #bbb;";

    this->setStyleSheet(styleValid);
}

void CheckQLineEdit::displayCheckNoValidFieldIcon()
{
    QString styleNoValid =
            "background: url(:/icons/img/img20/no20.png);"
            "background-position: right;"
            "background-repeat: no-repeat;     "
            "border-radius: 0px;"
            "height: 22px;"
            "border: 1px solid #bbb;";

    this->setStyleSheet(styleNoValid);
}


QPushButton *CheckQLineEdit::getBtnValid() const
{
    return _btnValid;
}

void CheckQLineEdit::setBtnValid(QPushButton *btnValid)
{
    _btnValid = btnValid;
}

bool CheckQLineEdit::isValid()
{
    return check(text());
}

}
}
}
