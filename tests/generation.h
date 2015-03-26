#ifndef GENERATION_H
#define GENERATION_H
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
    void GenerationSimpleTexBillingWithModel();
    void GenerationSimplePdfBillingWithModel();

    void GenerationBillingPdf();
};

//DECLARE_TEST(Generation)

#endif // GENERATION_H
