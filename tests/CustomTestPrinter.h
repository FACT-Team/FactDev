#ifndef CUSTOMTESTPRINTER_H
#define CUSTOMTESTPRINTER_H

#include <iostream>
#include <gtest/gtest.h>

namespace testing
{
namespace internal
{

enum GTestColor {
    COLOR_DEFAULT,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW
};
void ColoredPrintf(GTestColor color, const char* fmt, ...);

}
}

using namespace testing::internal;
using namespace testing;
using namespace std;

//! @see gtest.cc/PrettyUnitTestResultPrinter
class CustomTestPrinter : public EmptyTestEventListener
{

public:
    CustomTestPrinter();

    inline static void PrintTestName(const char * test_case, const char * test) {
      printf("%s.%s", test_case, test);
    }

    virtual void OnTestProgramStart(const UnitTest& unit_test) {}
    virtual void OnTestIterationStart(const UnitTest& unit_test, int iteration);
    virtual void OnEnvironmentsSetUpStart(const UnitTest& unit_test);
    virtual void OnEnvironmentsSetUpEnd(const UnitTest& unit_test) {}
    virtual void OnTestCaseStart(const TestCase& test_case);
    virtual void OnTestStart(const TestInfo& test_info);
    virtual void OnTestPartResult(const TestPartResult& result);
    virtual void OnTestEnd(const TestInfo& test_info);
    virtual void OnTestCaseEnd(const TestCase& test_case);
    virtual void OnEnvironmentsTearDownStart(const UnitTest& unit_test);
    virtual void OnEnvironmentsTearDownEnd(const UnitTest& unit_test) {}
    virtual void OnTestIterationEnd(const UnitTest& unit_test, int iteration);
    virtual void OnTestProgramEnd(const UnitTest& unit_test) {}

   private:
    static void PrintFailedTests(const UnitTest& unit_test);
};

string FormatCountableNoun(int count, const char* singular_form, const char* plural_form);
string FormatTestCount(int test_count);
string FormatTestCaseCount(int test_case_count);

#endif // CUSTOMTESTPRINTER_H
