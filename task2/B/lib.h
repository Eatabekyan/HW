#pragma once

#include <vector>

namespace my_lib {
    class SegmentTree {
    public:
        int sum(int Vec, int Tlft, int Trght, int l, int r);

        void update(int Vec, int Tlft, int Trght, int Pstn, int NVal);

        explicit SegmentTree(const std::vector<int> &x);

    private:
        void build(const std::vector<int> &x, int Vec, int Tlft, int Trght);

        std::vector<int> THIS;
        int N_N;
    };
}
