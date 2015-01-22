#include "checkqlineedit.h"
#include <QDebug>
CheckQLineEdit::CheckQLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

void CheckQLineEdit::fieldTextChanged(const QString &text) {

    if (check(text)) {
        displayCheckValidFieldIcon();
    } else {
        displayCheckNoValidFieldIcon();
    }
}

void CheckQLineEdit::displayCheckValidFieldIcon()
{
    QString styleValid =
            "background: url(:/icons/img/img20/yes_light20.png);"
            "background-position: right;"
            "background-repeat: no-repeat;     "
            "border-radius: 0px;"
            "height: 24px;"
            "border: 1px solid #bbb;";

    this->setStyleSheet(styleValid);
}

void CheckQLineEdit::displayCheckNoValidFieldIcon()
{
    QString styleNoValid =
            "background: url(:/icons/img/img20/no_light20.png);"
            "background-position: right;"
            "background-repeat: no-repeat;     "
            "border-radius: 0px;"
            "height: 24px;"
            "border: 1px solid #bbb;";

    this->setStyleSheet(styleNoValid);
}
