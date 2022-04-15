//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"
#include <Functions.h>

TEST(TestLeap, test1){
    ASSERT_TRUE(IsLeap(400));
    ASSERT_FALSE(IsLeap(100));
    ASSERT_TRUE(IsLeap(4));
    ASSERT_FALSE(IsLeap(5));
    ASSERT_THROW(IsLeap(-1), std::invalid_argument );
}
