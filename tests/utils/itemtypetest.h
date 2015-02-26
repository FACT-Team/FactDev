#ifndef ITEMTYPETEST_H
#define ITEMTYPETEST_H
#include "QTestRunner/testrunner.h"
#include "utils/itemtype.h"
using  namespace Utils;

class ItemTypeTest : public QObject
{
    Q_OBJECT

private slots:
    void constructorItemType();

    void getName();
    void setName();

    void getType();
    void setType();

    void getModel();

};

DECLARE_TEST(ItemTypeTest)

#endif // ITEMTYPETEST_H
