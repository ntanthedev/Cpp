#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    long long n = inf.readLong(), l = inf.readLong(), r = inf.readLong(), res = 0;

    if(l > r) 
        quitf(_wa, "test sai, l > r");

    vector<long long> a(n + 1);

    for(int i = 1; i <= n; i++) {
        a[i] = inf.readLong();
    }

    // long long  lmax = *max_element(a.begin() + 1, a.end());
    // long long lmin = *min_element(a.begin() + 1, a.end());

    // if(lmax - lmin > r - l)
    //     quitf(_pe, "max - min > r - l");

    int m = ouf.readInt();
    vector<int> b(m + 1, 0);

    for(int i = 1; i <= m; i++) {
        b[i] = ouf.readInt();
        if(i > 1 && b[i] <= b[i - 1]) 
            quitf(_wa, "sai thu tu vi tri");
        res += a[b[i]];
    }

    if(l <= res && res <= r)
        quitf(_ok, "ket qua dung");
    else 
        quitf(_wa, "ket qua sai");
}