#include "checklogin.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {

CheckLogin::CheckLogin(QWidget* w, QPushButton *btn)
    : CheckUntilField(w, btn)
{

}


bool CheckLogin::check(QString text)
{
    return text.length() != 0 && _login == text;
}

void CheckLogin::loginPreviousInputed(const QString &text)
{
    _login = text;
}

}
}
}
