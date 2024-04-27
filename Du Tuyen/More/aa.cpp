//problem "aa"
//created in 23:20:15 - Fri 26/04/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "NGONNUI"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, x;
    cin >> n >> x;

    if(x & 1) {
        if(n%x != 0 || n / x - (x - 1) / 2 < 1)
            cout << -1;
        else 
            for(int i = 0; i < x; i++) 
                cout << n / x - (x - 1) / 2 + i << " ";
    }
    else {
        if((n % (x / 2) == 0) && (n % x != 0) && ((2 * n) / x - (x - 1)) / 2 > 0)
            for(int i = 0; i < x; i++)
                cout << ((2 * n) / x - (x - 1)) / 2 + i << " ";
        else 
            cout << -1;
    }
}