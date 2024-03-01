#include<bits/stdc++.h>

#define int int64_t

using namespace std;

vector<int> bina(int x) {
    vector<int> y;
    int d = 0;
    while(x != 0) {
        if(x % 2 != 0)
            y.push_back(d);
        x /= 2;
        d++;
    }
    return y;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    auto vt = bina(10);
    
}