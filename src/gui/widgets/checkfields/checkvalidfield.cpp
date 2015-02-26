#include "checkvalidfield.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {
CheckValidField::CheckValidField(QWidget* w, QPushButton *btn) : CheckQLineEdit(w, btn) {

}


bool CheckValidField::check(QString) {
    return true;
}
}
}
}
