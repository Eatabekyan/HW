//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(TestAdd, test) {
    ASSERT_EQ(Add(1, 1), 2);
    ASSERT_FALSE(Add(2,1) == 4);
}
TEST(TestGMD, test) {
    ASSERT_EQ(GetMonthDays(400,2), 29);
    ASSERT_EQ(GetMonthDays(100,2), 28);
    ASSERT_EQ(GetMonthDays(400,4), 30);
    ASSERT_EQ(GetMonthDays(400,6), 30);
    ASSERT_EQ(GetMonthDays(400,9), 30);
    ASSERT_EQ(GetMonthDays(400,11), 30);
    ASSERT_EQ(GetMonthDays(400,1), 31);
    ASSERT_EQ(GetMonthDays(400,3), 31);
    ASSERT_EQ(GetMonthDays(100,5), 31);
    ASSERT_EQ(GetMonthDays(400,7), 31);
    ASSERT_EQ(GetMonthDays(400,8), 31);
    ASSERT_EQ(GetMonthDays(400,10), 31);
    ASSERT_EQ(GetMonthDays(400,12), 31);
    ASSERT_THROW(GetMonthDays(400,14), std::invalid_argument );
    ASSERT_THROW(GetMonthDays(400,0), std::invalid_argument );
    
}
bool iseq(int x){
    return x == 31;
}
