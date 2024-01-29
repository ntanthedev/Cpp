#include <bits/stdc++.h>

#define int long long

using namespace std;
const int mod = 1e9 + 7;

int n, k, f[1068][1068];

int dq(int i, int d) {
    if(i > n) {
        if(d < k)
            return 1;
    }
    if(f[i][d] != -1)
        return f[i][d] % mod;
    f[i][d] = 0;
    f[i][d] += dq(i + 1, 0);
    if(d + 1 < k)
        f[i][d] += dq(i + 1, d + 1);
    return f[i][d] % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "DNPK"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    while(cin >> n >> k) {
        for(int i = 0; i <= 1e3 + 5; i++) {
            for(int j = 0; j <= 1e3 + 5; j++) {
                f[i][j] = -1;
            }
        }
        cout << dq(1, 0) << '\n';
    }