#ifndef USERMODELTEST_H
#define USERMODELTEST_H
#include "QTestRunner/testrunner.h"
#include "models/user.h"

using namespace Models;


class UserModelTest : public QObject
{
    Q_OBJECT
public:
    UserModelTest();

private slots:
    void equals1();
    void equals2();
    void notEquals();
    void commitUpdate();
    void hydrat();
    void commitRemove();

    void workLoadTest();
private:
    User u1;
    User u2;
};

DECLARE_TEST(UserModelTest)
#endif // USERMODELTEST_H
