#include "checkuntilfield.h"

CheckUntilField::CheckUntilField(QWidget* w, QPushButton* btn) : CheckQLineEdit(w, btn) {

}

bool CheckUntilField::check(QString text) {
    return text.length() != 0;
}


