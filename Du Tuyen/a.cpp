//problem "a"
//created in 15:02:30 - Sun 28/07/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 1, x; i <= n; ++i) {
        cin >> x;
        int t = __builtin_popcount(x);
        cout << (1 << t) << " ";
    }    
}

/*
100101010

11
*/