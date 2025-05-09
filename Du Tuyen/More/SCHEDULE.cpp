//Written by: ntannn_
//created in 20:29:14 - Wed 28/02/2024
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

const int N = 3e5 + 10;
const ll MOD = 1e9 + 7;

struct pt {
    ll fi, se;
    int vt;
};

ll n;
pt a[N];

void solve() {
    sort(a + 1, a + 1 + n, [&](pt x, pt y){
        return x.se * y.fi < y.se * x.fi;
    });   
    ll d = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        d += a[i].se;
        ans += d * a[i].fi;
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; i++)
        cout << a[i].vt << " " ;
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].fi;
    for(int i = 1; i <= n; i++)
        cin >> a[i].se, a[i].vt = i;
}

#define task "SCHEDULE"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}