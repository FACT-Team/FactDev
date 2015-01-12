#include <QtTest/QtTest>
#include "testqstring.h"
int main(void) {
    TestQString* t = new TestQString();
    QTest::qExec(t);
}
