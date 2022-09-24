#include "gtest/gtest.h"
#include <helper.hpp>

TEST(HelperTest, test1) {
    //arrange
    //act
    //assert
    EXPECT_EQ (function(1,2),  3);
    
}

TEST(HelperTest, test2) {
    //arrange
    //act
    //assert
    EXPECT_FALSE (function(1,2)==4);
    
}