#include <gtest/gtest.h>
#include "CustomTestPrinter.h"

using testing::UnitTest;
using testing::TestEventListeners;

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    bool useCustomTestOutput = true;

    if (useCustomTestOutput) {
        UnitTest& unit_test = *UnitTest::GetInstance();
        TestEventListeners& listeners = unit_test.listeners();
        delete listeners.Release(listeners.default_result_printer());
        listeners.Append(new CustomTestPrinter());
    }

    return RUN_ALL_TESTS();
}
