#ifndef CONTRIBUTORYLISTTEST_H
#define CONTRIBUTORYLISTTEST_H
#include <QtTest/QtTest>
#include <QTestRunner/testrunner.h>

#include "models/contributorieslist.h"

using namespace Models;

class ContributoryListTest
{
public:
    ContributoryListTest();
private slots:
    void addProject();

};

#endif // CONTRIBUTORYLISTTEST_H
