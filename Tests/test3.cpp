#include <UnitTest++/UnitTest++.h>
#include <iostream>
struct MyFixture
{
    std::string testData;

    MyFixture() :
        testData("my test data")
    {
        std::cout << "my setup" << std::endl;
    }

    ~MyFixture()
    {
        std::cout << "my teardown" << std::endl;
    }
};

TEST_FIXTURE(MyFixture, MyTestCase)
{
    std::cout << testData << std::endl;
}
