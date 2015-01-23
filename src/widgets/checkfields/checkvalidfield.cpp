#include "checkvalidfield.h"

CheckValidField::CheckValidField(QWidget* w) : CheckQLineEdit(w) {

}


bool CheckValidField::check(QString text) {
    return true;
}
