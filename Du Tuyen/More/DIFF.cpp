#include<bits/stdc++.h>

#define int int64_t
#define fi first 
#define se second 

using namespace std;

int n, a[1000009], lef = INT_MAX, ans = 0;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define task "DIFF"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;
    a[0] = 0; 
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ans = max(ans, a[i] - lef);
        lef = min(lef, a[i]);
    }    
    cout << ans;
}