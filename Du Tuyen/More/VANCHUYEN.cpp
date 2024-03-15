#include<bits/stdc++.h>

#define int int64_t
const int N = 1e5 + 9;

using namespace std;

int n, a[N], S, res = 0;
bool L[20000009];

void sub1() {
    memset(L, false, sizeof(L));
    L[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = S; j >= a[i]; j--) {
            if(j >= a[i] && L[j-a[i]])
                L[j] = 1; 
        }
    }
    for(int i = S; i >= 0; i--)
        if(L[i])
            return cout << i, void();
}

void solve() {
    cin >> S >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i], res += a[i];
    if(S * n <= 2e7)
        sub1();
    else 
        sub1();
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "VANCHUYEN"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    solve();
}