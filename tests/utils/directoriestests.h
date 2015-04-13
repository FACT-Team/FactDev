#ifndef DIRECTORIESTESTS_H
#define DIRECTORIESTESTS_H
#include "QTestRunner/testrunner.h"
#include "models/user.h"
#include "utils/directories.h"

class DirectoriesTests : public QObject
{
    Q_OBJECT
public:
    DirectoriesTests();
    ~DirectoriesTests();
private slots:
    void validDirectoriesTest();
};

DECLARE_TEST(DirectoriesTests)

#endif // DIRECTORIESTESTS_H
