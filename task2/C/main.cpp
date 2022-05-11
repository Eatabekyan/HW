#include <random>
#include <stdio.h>
#include "main.h"

int main() {
    int N  = rand() % 10 + 2;
    std::vector<int> X(N);
    for (int i = 0; i < N; i++) {
        X[i] = rand() % 10000;
    }



    my_lib::SegmentTree st(X);



    for (int i = 0; i < 1000; i++) {
        if (i % 10 == 0) {
            printf("%d\n",  i);
        }
        int Lft = rand() % N;
        int Rght = rand() % N;
        if (Lft > Rght) {
            std::swap(Lft, Rght);
        }



        printf("%d\n", st.sum(1, 0, N - 1, Lft, Rght));
    }
}
////////////////////////
