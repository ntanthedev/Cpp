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

ll m, n, x;
map<ll, ll> a, b;

void solve() {
    ll ans = 0;
    for(auto i : a) {
        if(b[i.fi] < i.se && b[i.fi] != 0)
            ans += b[i.fi];
        else
            ans += i.se;
    }
    cout << ans;
}

void init() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++) {
        cin >> x;
        a[x]++;
    }
    for(int i = 1; i <= n; i++) {
        cin >> x;
        b[x]++;
    }
}

#define task "DELNUM"
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
    cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}