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
        qDebug() << "X";
    }
}

void CheckQLineEdit::displayCheckValidFieldIcon()
{
    QString styleValid =
            "background: url(:/icons/yes);"
            "background-position: right;"
            "background-repeat: no-repeat;     "
            "border-radius: 0px;"
            "height: 23px;"
            "border: 1px solid #bbb;";

    this->setStyleSheet(styleValid);
}

void CheckQLineEdit::displayCheckNoValidFieldIcon()
{
    QString styleNoValid =
            "background: url(:/icons/no);"
            "background-position: right;"
            "background-repeat: no-repeat;     "
            "border-radius: 0px;"
            "height: 23px;"
            "border: 1px solid #bbb;";

    this->setStyleSheet(styleNoValid);
}
