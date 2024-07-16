#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
const int N = 1e6 + 9;
const ll MOD = 1e9 + 3;
const ll base = 31;

ll ans = 0, n, k, m, POW[N], Hasha[N], Hashb[N];
string a, b;

ll get_hasha(ll i, ll j) {
    return (Hasha[j] - Hasha[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

ll get_hashb(ll i, ll j) {
    return (Hashb[j] - Hashb[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

ll check(ll x) {
    ans = 0;
    for(int i = 1; i <= n - x + 1; i++) {
        ll l = get_hasha(i, i + x - 1);
        ll r = get_hashb(n - (i + x - 1) + 1, n - i + 1);
        if(l == r)
            ans++;
    }
    return ans;
}

void solve() {
    n = a.size();
    a = ' ' + a;
    b = ' ' + b;
    POW[0] = 1;
    Hasha[0] = 0;
    Hashb[0] = 0;
    for(int i = 1; i <= n; i++) {
        POW[i] = (POW[i - 1] * base) % MOD;
    }
    for(int i = 1; i <= n; i++) {
        Hasha[i] = (Hasha[i - 1] * base + a[i] - 'a' + 1) % MOD;
    }
    for(int i = 1; i <= n; i++) {
        Hashb[i] = (Hashb[i - 1] * base + b[i] - 'a' + 1) % MOD;
    }

    cout << check(m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define task "pw"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> k >> m;
    cin >> a;
    b = a;
    reverse(all(b));

    solve();
}
