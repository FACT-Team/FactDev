#include "pointerstest.h"

void PointersTest::deleteIfNotNullTest() {
    QObject* test = new QObject;
    Utils::pointers::deleteIfNotNull(test);
    test = 0;
    Utils::pointers::deleteIfNotNull(test);
    Utils::pointers::deleteIfNotNull(test);
    Utils::pointers::deleteIfNotNull(test);
}
