//Written by: ntannn_
//created in 09:21:02 - Mon 01/07/2024
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;
const int base = 311;

string a, b;
ll Ha = 0, Hb[N], P[N];

ll get(int i, int j) {
    return (Hb[j] - Hb[i - 1] * P[j - i + 1] + MOD * MOD) % MOD;
}

void solve() {
    ll n = a.size(), m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    Hb[0] = 0;
    P[0] = 1;

    for(int i = 1; i <= m + 1; i++) 
        P[i] = (P[i - 1] * base) % MOD;
    
    for(int i = 1; i <= n; i++) 
        Ha = (Ha * base + a[i] - 'a') % MOD;
    
    for(int i = 1; i <= m; i++) 
        Hb[i] = (Hb[i - 1] * base + b[i] - 'a') % MOD;

    for(int i = 1; i <= m - n + 1; i++) {
        if(Ha == get(i, i + n - 1))
            cout << i << " ";
    }
}

void init() {
    cin >> b >> a;
}

#define task "a"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}