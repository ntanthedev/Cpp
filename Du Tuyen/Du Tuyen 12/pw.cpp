#include <bits/stdc++.h>
#define bt "T"
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); ++(i))
#define FORD(i, a, b) for(int(i) = (a); (i) >= (b); --(i))

using namespace std;

int mulmod(int a, int b, int M) {
    if(b == 0)
        return 0;
    int t = mulmod(a, b / 2, M) % M;
    if(b & 1)
        return ((t + t) % M + a % M) % M;
    else
        return (t + t) % M;
}

int powmod(int a, int b, int M) {
    int res = 1;
    a %= M;
    while(b > 0) {
        if(b & 1)
            res = (res * a) % M;
        b = b >> 1;
        a = (a * a) % M;
    }
    return res;
}

int k, m, l, r, cnt;
string s, x;

bool dx(string x) {
    int l = 0, r = x.size() - 1;
    while(l <= r) {
        if(x[l] != x[r])
            return 0;
        ++l;
        --r;
    }
    return 1;
}

void solve() {
    cin >> k >> m;
    cin >> s;
    if(k == 1)  // sub 1, 2
    {
        for(int i = 0; i <= s.size() - m; ++i)
            if(dx(s.substr(i, m)))
                ++cnt;
        cout << cnt;
    } else {
        for(int i = 1; i <= k - 1; ++i) {
            cin >> l >> r;
            --l, --r;
            x += s.substr(l, r - l + 1);
        }
        for(int i = 0; i <= s.size() - m; ++i)
            if(dx(s.substr(i, m) + x) || dx(x + s.substr(i, m)))
                ++cnt;
        cout << cnt;
    }
}

int main() {
    #define task "pw"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t = 1;  // cin >> t;
    while(t--)
        solve();
    return 0;
}