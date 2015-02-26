#include "itemtypetest.h"


void ItemTypeTest::constructorItemType()
{
    ItemType itemType(ItemType::BILLING, "Facture");
    QCOMPARE(2, itemType.getType());
    QVERIFY("Facture" == itemType.getName());
}

void ItemTypeTest::getName()
{
    ItemType itemType(ItemType::BILLING, "Facture");
//    QVERIFY("Facture" == itemType.getName());
}

void ItemTypeTest::setName()
{
    ItemType itemType(ItemType::BILLING, "Facture");
    itemType.setName("Projet");
    QVERIFY("Projet" == itemType.getName());
}

void ItemTypeTest::getType()
{
    ItemType itemType(ItemType::BILLING, "Facture");
    QCOMPARE(2, itemType.getType());
}

void ItemTypeTest::setType()
{
    ItemType itemType(ItemType::BILLING, "Facture");
    itemType.setType(ItemType::CUSTOMER);
    QCOMPARE(0, itemType.getType());
}

void ItemTypeTest::getModel()
{
    ItemType itemType1(ItemType::CUSTOMER, "Client");
    QVERIFY(Customer(1).getId() == itemType1.getModel(1)->getId());
    QVERIFY(dynamic_cast<Customer*>(itemType1.getModel(1)) != 0);

    ItemType itemType2(ItemType::PROJECT, "Projet");
    QVERIFY(Project(1).getId() == itemType2.getModel(1)->getId());
    QVERIFY(dynamic_cast<Project*>(itemType2.getModel(1)) != 0);

    ItemType itemType3(ItemType::BILLING, "Facture");
    QVERIFY(Billing(1).getId() == itemType3.getModel(1)->getId());
    QVERIFY(dynamic_cast<Billing*>(itemType3.getModel(1)) != 0);

    ItemType itemType4(ItemType::QUOTE, "Devis");
    QVERIFY(Billing(1).getId() == itemType4.getModel(1)->getId());
    QVERIFY(dynamic_cast<Billing*>(itemType4.getModel(1)) != 0);

}




