#include "gtest/gtest.h"
#include "models/customer.h"

class AdditionTest : public ::testing::Test {
protected:
      virtual void SetUp() {
      }

      virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
      }
};

    TEST_F(AdditionTest,twoValsfues){
        Customer* c = new Customer;
        c->commit();
    }
    TEST_F(AdditionTest,az){
        EXPECT_EQ(1, 2);
    }TEST_F(AdditionTest,z){
        EXPECT_EQ(1, 2);
    }TEST_F(AdditionTest,sdf){
        EXPECT_EQ(1, 2);
    }TEST_F(AdditionTest,xv){
        EXPECT_EQ(1, 2);
    }
