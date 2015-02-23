#ifndef USERDATABASETEST_H
#define USERDATABASETEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "QTestRunner/testrunner.h"
#include "models/project.h"

class UserDatabaseTest : public QObject
{
    Q_OBJECT

public:
    UserDatabaseTest();

private slots:
    void getUserTest(void);
    void updateUserTest(void);
    void noGetUserTest();
};

DECLARE_TEST(UserDatabaseTest)
#endif // USERDATABASETEST_H
