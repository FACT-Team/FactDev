#ifndef TESTOUILLE_H
#define TESTOUILLE_H
#include "QTestRunner/testrunner.h"


class Generation : public QObject
{
    Q_OBJECT

public:
    Generation();

private slots:
    void testTemplate();
    void testFileTemplate();
    void GenerationSimpleBilling();
};

DECLARE_TEST(Generation)

#endif // TESTOUILLE_H
