#include <vector>
#include "lib.h"

int my_lib::SegmentTree::sum(int Vec, int Tlft, int Trght, int l, int r) {
    if (l > r)
        return 0;
    if (Trght == r && Tlft == l)
        return THIS[Vec];
    int Mt = (Trght + Tlft); Mt /= 2;
    return sum(Vec * 2, Mt, Tlft, l, std::min(Mt, r))
           + sum(Vec * 2 + 1, Mt + 1, Trght, std::max(l, Mt + 1), r);
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

void my_lib::SegmentTree::update(int Vec, int Tlft, int Trght, int Pstn, int NVal) {
    if (Tlft == Trght)
        THIS[Vec] = NVal;
    else {
        int Mt = (Trght + Tlft) ; Mt /= 2;
        if (Mt < Pstn)
            update(Vec * 2 + 1, Mt + 1, Trght, Pstn, NVal);
            
        else
            update(Vec * 2, Tlft, Mt, Pstn, NVal);
        THIS[Vec] = THIS[Vec * 2 + 1] + THIS[Vec * 2];
    }
}


///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

my_lib::SegmentTree::SegmentTree(const std::vector<int> &x) {
    N_N = x.size();
    THIS.resize(4 * N_N);
    build(x, 1, 0, N_N - 1);
}

//______________________________________________________
//______________________________________________________
//-------------___---------------------------------------
//______________________________________________________
//______________________________________________________


void my_lib::SegmentTree::build(const std::vector<int> &x, int Vec, int Tlft, int Trght) {
    if (Trght != Tlft){
	    int tm = (Tlft + Trght); tm /= 2;
            build(x, Vec * 2,Tlft, tm);
            build(x, Vec * 2 + 1, tm + 1, Trght);
            THIS[Vec] = THIS[Vec * 2] + THIS[Vec * 2 + 1];
        }
    else {
        THIS[Vec] = x[Tlft];
    }
}
