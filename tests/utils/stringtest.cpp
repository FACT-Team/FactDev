#include "stringtest.h"

StringTest::StringTest()
{

}

void StringTest::firstLetterToUpperTest()
{
    QVERIFY(Utils::String::firstLetterToUpper("MACHIN") == "MACHIN");
    QVERIFY(Utils::String::firstLetterToUpper("mACHIN") == "MACHIN");
    QVERIFY(Utils::String::firstLetterToUpper("machin") == "Machin");
}

void StringTest::getExtensionFile() {
    QVERIFY(Utils::String::getExtensionFile("machintruc.jpg") == "jpg");
    QVERIFY(Utils::String::getExtensionFile("beautiful_stuff.test.pdf") == "pdf");
    QVERIFY(Utils::String::getExtensionFile("accentué.png") == "png");
    QVERIFY(Utils::String::getExtensionFile("bidule/chose/chouette.png") == "png");
}
