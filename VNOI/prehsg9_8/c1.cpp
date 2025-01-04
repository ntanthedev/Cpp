//problem "a"
//created in 09:49:34 - Sat 04/01/2025

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int n, k;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "a"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> k;

    int ans = 0;

    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            if(i + k - 1 <= n) {
                ans++;
                if(j + k <= i) ans++;
            }
        }
    }

    cout << ans;
}