//template for some simple code by ntannn_
//created in 15:08:59 - Tue 23/01/2024
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

ll n, m;
ll a[N], b[N], kc[N];

bool check(ll d) {
    for(int i = 1; i <= m; i++) 
        if(d < kc[i])
            return false;
    return true;
}

void solve() {
    sort(a + 1, a + 1 + m);
    sort(b + 1, b + 1 + n);
    for(int i = 1; i <= m; i++) {
        if(a[i] < b[1])
            kc[i] = b[1] - a[i];
        else if(a[i] > b[n])
            kc[i] = a[i] - b[n];
        else {
            ll t = lower_bound(b + 1, b + 1 + n, a[i]) - b;
            kc[i] = min(b[t] - a[i], a[i] - b[t-1]);
        }
    }
    ll l = 0, r = 1e16, ans;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else 
            l = mid + 1;
    }
    cout << ans;
}

void init() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) 
        cin >> b[i];
}

#define task "CHIEUSANG"
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