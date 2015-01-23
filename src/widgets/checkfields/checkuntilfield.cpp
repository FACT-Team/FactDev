#include "checkuntilfield.h"

CheckUntilField::CheckUntilField(QWidget *w) : CheckQLineEdit(w) {

}

bool CheckUntilField::check(QString text) {
    return text.length() != 0;
}


