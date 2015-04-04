#ifndef STRINGTEST_H
#define STRINGTEST_H
#include <QObject>

#include "QTestRunner/testrunner.h"
#include "utils/string.h"

class StringTest : public QObject
{
    Q_OBJECT
public:
    StringTest();
private slots:
    void firstLetterToUpperTest(void);
    void getExtensionFile();
};

DECLARE_TEST(StringTest)

#endif // STRINGTEST_H
