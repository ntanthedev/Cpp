//template for some simple code by ntannn_
//created in 14:13:41 - Tue 30/01/2024
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

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;

struct pt {
    ll fi, se, vt;
};

ll n, u, v, k = 1, mmax = -1;
vi ans;
vector<pt> a, temp;
vector<bool> pick;

void solve() {
    sort(all(temp), [&] (pt x, pt y) {
        return x.fi < y.fi || (x.fi == y.fi && x.se > y.se);
    });
    
    if(temp.front().fi > v || temp.back().se < u)
        return cout << -1, void();

    for(int i = 0; i < n; i++) {
        if(mmax < u || temp[i].fi > v)
            continue;
        if(i > 0 && temp[i].se <= temp[i-1].se)
            continue;
        while(a.size() > 1 && temp[i].fi <= a[a.size()-2].se) {
            pick[a.back().vt-1] = 0;
            a.pop_back();
        }
        while(a.size() != 0 && temp[i].fi <= u && a.back().fi <= u)
            a.pop_back();
        pick[i] = 1;
        a.eb(temp[i]);
        if(a.back().se >= v)
            break;
    }
    cerr << "\x1b[31mstart debug: \n";
    cerr << "check 2\n";
    cerr << "end of debug\e[39m \n";
    for(int i = 1; i < a.size(); i++) {
        if(a[i].fi > a[i-1].se)
            return cout << -1, void();
    }
    cout << a.size() << '\n';
    sort(all(a), [&] (pt x, pt y) {
        return x.vt < y.vt;
    });
    for(auto i : a)
        cout << i.vt << ' ';
}

void init() {
    cin >> n >> u >> v;
    temp.resize(n);
    pick.resize(n, false);
    for(int i = 0; i < n; i++) {
        cin >> temp[i].fi >> temp[i].se;
        temp[i].vt = i+1;
        mmax = max(mmax, temp[i].se);
    }
    // cout << "check";
    // exit(0); 
}

#define task "COVER"
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