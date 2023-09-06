#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll n, res = 0, a[N], dp[N], s[N], L[N], Lmax[N];

struct sub1 {
    ll x[30], gmax = 0;
    
    void check() {
        ll res = 0, le = 0, d = 0;
        x[n+1] = 0;
        for(int i = 1; i <= n+1; i++) {
            if(x[i])
                ++le, d += a[i];
            else 
                res += d*le;
        }
        gmax = max(gmax, res);
    }
    void quaylui(int i) {
        for(int j = 0; j <= 1; j++) {
            x[i] = j;
            if(i == n) 
                check();
            else 
                quaylui(i+1);
        }
    }

    void solve() {
        quaylui(1);
        cout << gmax;
    }
} sub1;

void solve() {
    if(n <= 20) {
        sub1.solve();
        return ;
    }
    memset(L, 1, sizeof(L));
    for(int i = 2; i <= n; i++) {
        if((a[i] + dp[i - 1]) * (L[i - 1] + 1) > dp[i-1] * L[i-1]) { 
            dp[i] = dp[i-1] + a[i];
            L[i] = L[i-1] + 1;
            Lmax[i] = dp[i];
        }
        else {
            dp[i] = a[i];
            L[i] = 1; 
            Lmax[i] = a[i];
        } 
    }
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
}

#define task "WARRAY"
int32_t main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    // cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}
