#include "checkvalidfield.h"

CheckValidField::CheckValidField(QWidget* w, QPushButton *btn) : CheckQLineEdit(w, btn) {

}


bool CheckValidField::check(QString text) {
    return true;
}
