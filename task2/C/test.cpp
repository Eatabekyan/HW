#include "gtest/gtest.h"
#include "B/lib.h"
#include "A/index.h"

TEST(TrTest, SegTrTst) {
    int Num  = 100;
    std::vector<int> Data_v(Num);
    for (int i = 0; i < Num; i++) {
        Data_v[i] = rand() % Num;
        if (rand() % 2) {
            Data_v[i] *= -1;
        }
    }

    my_lib::SegmentTree st(Data_v);
    for (int i = 0; i < Num; i++) {
        int Lft = rand() % Num;
        int Rght = rand() % Num;
        if (Rght < Lft) {
            std::swap(Lft, Rght);
        }
        int expS = 0;
        for (int j = Lft; j <= Rght; j++) {
            expS += Data_v[j];
        }
        ASSERT_EQ(expS, st.sum(1, 0, Num - 1, Lft, Rght));
    }
    printf("passed all tests!\n");
};

TEST(NTest, gcd_test) {
    for (int i = 0; i < 1000; i++) {
        int x = rand() % 1000 + 1;
        int y = rand() % 1000 + 1;

        int true_gcd = 1;
        for (int a = 1; a <= std::min(x, y); a++) {
            if (x % a == 0 && y % a == 0) {
                true_gcd = a;
            }
        }
        ASSERT_EQ(trueGcd, gcd(x, y));
    }
    printf("passed all tests!\n");
}
