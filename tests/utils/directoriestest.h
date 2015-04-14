#ifndef DIRECTORIESTEST_H
#define DIRECTORIESTEST_H
#include "QTestRunner/testrunner.h"
#include "utils/directories.h"
#include "models/user.h"
class DirectoriesTest : public QObject
{
    Q_OBJECT
public:
    DirectoriesTest();
    ~DirectoriesTest();
private slots:
    void validDirectoriesTest();
};

DECLARE_TEST(DirectoriesTest)
#endif // DIRECTORIESTEST_H
