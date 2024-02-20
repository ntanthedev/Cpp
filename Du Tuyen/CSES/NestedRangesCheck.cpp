//template for some simple code by ntannn_
//created in 08:44:48 - Tue 20/02/2024
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

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

struct pt {
    int fi, se, vt;
};
pt a[N];
ll n;
vi c;

void solve() {
    sort(a + 1, a + 1 + n, [&](pt x, pt y){
        return x.fi < y.fi || (x.fi == y.fi && x.se < y.se);
    });
    c.resize(n + 1, 0);
    pll lens = {a[1].vt, a[1].se};
    for(int i = 2; i <= n; i++) {
        if(a[i].se <= lens.se) 
            c[a[i].vt] = 2;
        if(a[i].se > lens.se)
            lens = {a[i].fi, a[i].se};
    }
    lens = {a[n].fi, a[n].se};
    for(int i = n-1; i >= 1; i--) {
        if(a[i].se >= lens.se)
            c[a[i].vt] = 1;
        if(a[i].se < lens.se)
            lens = {a[i].fi, a[i].se};
    }
    for(int i = 1; i <= n; i++)
        cout << (c[i] == 1 ? 1 : 0) << " " ;
    cout << '\n';
    for(int i = 1; i <= n; i++)
        cout << (c[i] == 2 ? 1 : 0) << " " ;
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        a[i].vt = i;
    }
}

#define task "NestedRangesCheck"
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