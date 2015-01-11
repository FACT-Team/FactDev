#include <limits.h>
#include "gtest/gtest.h"

    class AutreTest : public ::testing::Test {
     protected:
      virtual void SetUp() {
      }

      virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
      }
    };

    TEST_F(AutreTest,a321){
        EXPECT_EQ(1, 2);
    }
    TEST_F(AutreTest,ss){
        EXPECT_EQ(1, 2);
    }TEST_F(AutreTest,zcxvxcv){
        EXPECT_EQ(1, 2);
    }TEST_F(AutreTest,ssdfsdfdf){
        EXPECT_EQ(1, 2);
    }TEST_F(AutreTest,xsssv){
        EXPECT_EQ(1, 2);
    }
