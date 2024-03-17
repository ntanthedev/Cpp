#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define task "WEI"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n;
    pair<int, int> p1 = {0, 0}, p2 = {0, 0};
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        p1.fi = (a[i] > a[p1.fi] ? i : p1.fi);
    }
    for(int i = 0; i < n; i++) {
        if(i != p1.fi)
            p1.se = (a[i] > a[p1.se] ? i : p1.se);
    }
    for(int i = 0; i < n; i++) 
        p2.fi = (a[i] > a[p2.fi] ? i : p2.fi);
    for(int i = 0; i < n; i++) 
        p2.se = (a[i] > a[p2.se] ? i : p2.se);
    cout << max(abs(a[p1.fi] + a[p1.se]), abs(a[p2.fi], a[p2.se]));
}