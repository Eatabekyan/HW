code = '''
#pragma once
#include <algorithm>
int gcd(int a, int b) {
    while(b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}
'''

file = open("index.h", "w+")
file.write(code)
file.close()
