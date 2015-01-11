#include "CustomTestPrinter.h"

CustomTestPrinter::CustomTestPrinter()
{
}

// Fired before each iteration of tests starts.
void CustomTestPrinter::OnTestIterationStart(const UnitTest& unit_test, int iteration)
{
    if (GTEST_FLAG(repeat) != 1) {
        printf("\nRepeating all tests (iteration %d) . . .\n\n", iteration + 1);
    }

    const char* const filter = GTEST_FLAG(filter).c_str();

    if (GTEST_FLAG(shuffle)) {
        ColoredPrintf(COLOR_YELLOW,
                      "Note: Randomizing tests' orders with a seed of %d .\n",
                      unit_test.random_seed());
    }

    ColoredPrintf(COLOR_GREEN,  "[==========] ");
    printf("Running %s from %s.\n",
           FormatTestCount(unit_test.test_to_run_count()).c_str(),
           FormatTestCaseCount(unit_test.test_case_to_run_count()).c_str());
    fflush(stdout);
}

void CustomTestPrinter::OnEnvironmentsSetUpStart(const UnitTest& /*unit_test*/)
{
    ColoredPrintf(COLOR_GREEN,  "[----------] ");
    printf("Global test environment set-up.\n");
    fflush(stdout);
}

void CustomTestPrinter::OnTestCaseStart(const TestCase& test_case)
{
    const std::string counts = FormatCountableNoun(test_case.test_to_run_count(), "test", "tests");
    ColoredPrintf(COLOR_GREEN, "[----------] ");
    printf("%s from %s", counts.c_str(), test_case.name());
    printf("\n");
    fflush(stdout);
}

void CustomTestPrinter::OnTestStart(const TestInfo& /*test_info*/)
{
    /*ColoredPrintf(COLOR_GREEN,  "[ RUN      ] ");
    PrintTestName(test_info.test_case_name(), test_info.name());
    printf("\n");
    fflush(stdout);*/
}

// Called after an assertion failure.
void CustomTestPrinter::OnTestPartResult(
    const TestPartResult& result)
{
    // If the test part succeeded, we don't need to do anything.
    if (result.type() == TestPartResult::kSuccess) {
        return;
    }

    // Print failure message from the assertion (e.g. expected this and got that).
    cout << endl <<  result.file_name() << ":"  << result.line_number() << ": Failure - "<< result.file_name() << endl << result.summary() << endl << endl;
    fflush(stdout);
}

void CustomTestPrinter::OnTestEnd(const TestInfo& test_info)
{
    if (test_info.result()->Passed()) {
        return;
        ColoredPrintf(COLOR_GREEN, "[       OK ] ");
    } else {
        ColoredPrintf(COLOR_RED, "[  FAILED  ] ");
    }
    PrintTestName(test_info.test_case_name(), test_info.name());

    if (GTEST_FLAG(print_time)) {
        printf(" (%s ms)\n", internal::StreamableToString(
                   test_info.result()->elapsed_time()).c_str());
    } else {
        printf("\n");
    }
    fflush(stdout);
}

void CustomTestPrinter::OnTestCaseEnd(const TestCase& test_case)
{
    if (!GTEST_FLAG(print_time)) {
        return;
    }

    const std::string counts =
        FormatCountableNoun(test_case.test_to_run_count(), "test", "tests");
    ColoredPrintf(COLOR_GREEN, "[----------] ");
    printf("%s from %s (%s ms total)\n\n",
           counts.c_str(), test_case.name(),
           internal::StreamableToString(test_case.elapsed_time()).c_str());
    fflush(stdout);
}

void CustomTestPrinter::OnEnvironmentsTearDownStart(
    const UnitTest& /*unit_test*/)
{
    ColoredPrintf(COLOR_GREEN,  "[----------] ");
    printf("Global test environment tear-down\n");
    fflush(stdout);
}

// Internal helper for printing the list of failed tests.
void CustomTestPrinter::PrintFailedTests(const UnitTest& unit_test)
{
    const int failed_test_count = unit_test.failed_test_count();
    if (failed_test_count == 0) {
        return;
    }

    for (int i = 0; i < unit_test.total_test_case_count(); ++i) {
        const TestCase& test_case = *unit_test.GetTestCase(i);
        if (!test_case.should_run() || (test_case.failed_test_count() == 0)) {
            continue;
        }
        for (int j = 0; j < test_case.total_test_count(); ++j) {
            const TestInfo& test_info = *test_case.GetTestInfo(j);
            if (!test_info.should_run() || test_info.result()->Passed()) {
                continue;
            }
            ColoredPrintf(COLOR_RED, "[  FAILED  ] ");

            printf("%s.%s", test_case.name(), test_info.name());
            printf("\n");
        }
    }
}

void CustomTestPrinter::OnTestIterationEnd(const UnitTest& unit_test, int /*iteration*/)
{
    ColoredPrintf(COLOR_GREEN,  "[==========] ");
    printf("%s from %s ran.",
           FormatTestCount(unit_test.test_to_run_count()).c_str(),
           FormatTestCaseCount(unit_test.test_case_to_run_count()).c_str());
    if (GTEST_FLAG(print_time)) {
        printf(" (%s ms total)",
               internal::StreamableToString(unit_test.elapsed_time()).c_str());
    }
    printf("\n");
    ColoredPrintf(COLOR_GREEN,  "[  PASSED  ] ");
    printf("%s.\n", FormatTestCount(unit_test.successful_test_count()).c_str());

    int num_failures = unit_test.failed_test_count();
    if (!unit_test.Passed()) {
        const int failed_test_count = unit_test.failed_test_count();
        ColoredPrintf(COLOR_RED,  "[  FAILED  ] ");
        printf("%s, listed below:\n", FormatTestCount(failed_test_count).c_str());
        PrintFailedTests(unit_test);
        printf("\n%2d FAILED %s\n", num_failures,
               num_failures == 1 ? "TEST" : "TESTS");
    }

    int num_disabled = unit_test.reportable_disabled_test_count();
    if (num_disabled && !GTEST_FLAG(also_run_disabled_tests)) {
        if (!num_failures) {
            printf("\n");  // Add a spacer if no FAILURE banner is displayed.
        }
        ColoredPrintf(COLOR_YELLOW,
                      "  YOU HAVE %d DISABLED %s\n\n",
                      num_disabled,
                      num_disabled == 1 ? "TEST" : "TESTS");
    }
    // Ensure that Google Test output is printed before, e.g., heapchecker output.
    fflush(stdout);
}

string FormatCountableNoun(int count, const char* singular_form, const char* plural_form) {
  return internal::StreamableToString(count) + " " +
      (count == 1 ? singular_form : plural_form);
}

string FormatTestCount(int test_count) {
  return FormatCountableNoun(test_count, "test", "tests");
}

string FormatTestCaseCount(int test_case_count) {
  return FormatCountableNoun(test_case_count, "test case", "test cases");
}
