code = '''
#pragma once
#include <algorithm>

int faktorial(int a) {
    int s=1;
    while(a!=1) {
        s*=a;
	a--;
    }
    return s;
}
'''

file = open("index.h", "w+")
file.write(code)
file.close()
