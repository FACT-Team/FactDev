//ProjectTestsAll.cpp
#include <iostream>

#include <UnitTest++/UnitTest++.h>

#define RUN_IN_RELEASE(x) extern void x(); x()
SUITE(TEST)
{

    TEST(FailSpectacularly)
    {
        CHECK(false);

    }

    TEST(FailSpectacularly2)
    {
        CHECK(true);
    }
}


int main() {
    return UnitTest::RunAllTests();
}
