#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    long long n = inf.readInt();
    long long d = inf.readLong();
    std::vector<int> h(n + 2);
    for (int i = 1; i <= n; i++) {
        h[i] = inf.readLong();
    }

    int correct_k = ouf.readInt();
    int contestant_k = ans.readInt();

    if (contestant_k != correct_k) {
        quitf(_wa, "Incorrect k value");
    }

    if(ouf.eof()) 
        quitp(50, "Correct k, but have no jump sequence");

    std::vector<long long> a;
    for (int i = 0; i < contestant_k; i++) {
        a.push_back(ouf.readInt());
    }
    
    for(auto i : a) {
        if(1 > i || i > n)
            quitp(50, "index i have value out of range [1, n]");
    }

    bool ok;
    for(int i = 1; i < contestant_k; i++) {
        if(abs(h[a[i]] - h[a[i - 1]]) >= d && a[i] > a[i - 1])
            ok = 1;
        else 
            quitp(50, "Correct k, but incorrect jump sequence");
    }
    
    quitf(_ok, "Correct answer");   
}