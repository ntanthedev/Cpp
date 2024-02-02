#include<bits/stdc++.h>

// #define int long long

typedef long long ll;

using namespace std;

ll n, a[1000009], ans = 0, s;

void sub1() {
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            ll res = 0;
            for(int k = i; k <= j; k++) {
                res += a[k];
                if(res == s) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "BRIDGE"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> s;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    if(n <= 100) 
        sub1();
}