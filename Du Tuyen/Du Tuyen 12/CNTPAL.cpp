//problem "CNTPAL"
//created in 07:39:50 - Wed 24/07/2024

#include<bits/stdc++.h>

#define all(x) x.begin(), x.end()
const int64_t MOD = 1e9 + 7;
const int base = 31;
const int N = 5e3 + 5;

using namespace std;

typedef long long ll;

string a, b;
ll P[N], Ha[N], Hb[N], s[N];

ll get_hash_a(ll i, ll j) {
    return (Ha[j] - Ha[i - 1] * P[j - i + 1] + MOD * MOD) % MOD;
}

ll get_hash_b(ll i, ll j) {
    return (Hb[j] - Hb[i - 1] * P[j - i + 1] + MOD * MOD) % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "CNTPAL"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> a;
    
    b = a;
    reverse(all(b));

    ll n = a.size();
    
    b = ' ' + b;
    a = ' ' + a;

    P[0] = 1;
    Ha[0] = 0;
    Hb[0] = 0;
    for(ll i = 1; i <= n; i++) {
        P[i] = (P[i - 1] * base) % MOD;
    }

    for(ll i = 1; i <= n; i++) { 
        Ha[i] = (Ha[i - 1] * base + a[i] - 'a' + 1) % MOD;
    }

    for(ll i = 1; i <= n; i++) { 
        Hb[i] = (Hb[i - 1] * base + b[i] - 'a' + 1) % MOD;
    }

    vector<pair<ll, ll>> f;

    for(ll i = 1; i <= n; i++) {
        for(ll j = i + 1; j <= n; j++) {
            if(get_hash_a(i, j) == get_hash_b(n - j + 1, n - i + 1))
                f.push_back({i, j});
        }
    }

    memset(s, 0, sizeof(s));

    for(int i = 0; i < f.size(); ++i) {
        s[f[i].second] += 1;
    }

    for(int i = 1; i <= n; i++)
        s[i] += s[i - 1];

    ll Q;

    cin >> Q;

    while(Q--) {
        ll x, y;

        cin >> x >> y;
        
        cout << s[y] - s[x] + (y - x + 1) << '\n';
    }
}
/*
caaaba
5
1 1 
1 4
2 3
4 6
4 5
*/