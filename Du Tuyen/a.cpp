//Written by: ntannn_
//created in 15:56:14 - Wed 27/03/2024
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
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

ll n, m, s[N], ans = 0;
pll a[N], gmax = {0, 0};

void solve() {
    sort(a + 1, a + 1 + m);

    for(int i = 1; i <= m; i++) 
        s[i] = s[i-1] + a[i].fi;
    

    ll t = upper_bound(a + 1, a + 1 + m, mp(gmax.se, 0LL)) - a;

    if(t <= m) {
        ans += (s[m] - s[t-1]);
        n -= (m - t + 1);
    }

    if(gmax.fi >= gmax.se) {
        n--;
        ans += n * gmax.se;
    }
    
    cout << ans;
}   

void init() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) 
        cin >> a[i].fi >> a[i].se, gmax = (a[i].se > gmax.se || (a[i].se == gmax.se && a[i].fi > gmax.fi) ? a[i] : gmax);
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