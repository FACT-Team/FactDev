#include <limits.h>
#include "gtest/gtest.h"

    class Machin : public ::testing::Test {
     protected:
      virtual void SetUp() {
      }

      virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
      }
    };

    TEST_F(Machin,twoValsfues){
        EXPECT_EQ(1, 1);
    }
    TEST_F(Machin,az){
        EXPECT_EQ(1, 1);
    }TEST_F(Machin,z){
        EXPECT_EQ(1, 1);
    }TEST_F(Machin,sdf){
        EXPECT_EQ(1, 1);
    }TEST_F(Machin,xv){
        EXPECT_EQ(1, 1);
    }
