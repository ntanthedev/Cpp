#include <bits/stdc++.h>

#define ll long long
#define fr(i, d, c) for(ll i = d; i <= c; i++)
#define fl(i, d, c) for(ll i = d; i >= c; i--)
const int N = 1e6 + 9, mod = 1e9 + 7;
using namespace std;

ll n, gt[N], ndgt[N], cnt[30];
string s;

ll bp(ll x) {
    return x * x % mod;
}

ll power(ll a, ll n) {
    if(!n)
        return 1;
    if(n & 1)
        return bp(power(a, n / 2)) * a % mod;
    return bp(power(a, n / 2));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> s;
    n = 1e6;
    gt[0] = 1;
    fr(i, 1, n) gt[i] = gt[i - 1] * i % mod;
    ndgt[n] = power(gt[n], mod - 2);
    fl(i, n - 1, 0) ndgt[i] = ndgt[i + 1] * (i + 1) % mod;
    for(auto x: s)
        cnt[x - 'a']++;

    ll ans = gt[s.size()];
    fr(i, 0, 25) {
        ans = ans * ndgt[cnt[i]] % mod;
    }
    cout << ans;
}