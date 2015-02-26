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
