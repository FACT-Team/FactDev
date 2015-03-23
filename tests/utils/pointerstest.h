#ifndef POINTERSTEST_H
#define POINTERSTEST_H
#include <QObject>

#include "QTestRunner/testrunner.h"
#include "utils/pointers.h"

class PointersTest : public QObject
{
Q_OBJECT
private slots:
    void deleteIfNotNullTest();
};

DECLARE_TEST(PointersTest)
#endif // POINTERSTEST_H
