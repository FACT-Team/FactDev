#include "pointerstest.h"

void PointersTest::deleteIfNotNullTest() {
    int* test = new int;
    Utils::pointers::deleteIfNotNull(test);
    QCOMPARE(test, 0);
    Utils::pointers::deleteIfNotNull(test);
    QCOMPARE(test, 0);
}
