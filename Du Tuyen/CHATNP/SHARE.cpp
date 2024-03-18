//Written by: ntannn_
//created in 20:59:45 - Sun 17/03/2024
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

ll n, a[N], k, arr = 0;

bool check(ll mid) {
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        res += min(mid, a[i]);
    }
    return (res >= k);
}

void solve() {
    if(arr < k)
        return cout << -1, void();
    arr /= n;
    if(k <= n) {
        for(int i = 1; i <= n; i++)
            cout << 1 << " ";
        exit(0);
    }
    ll l = 1, r = 1e9, ans = 0;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(check(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else 
            l = mid + 1;
    }
    vi f(n + 1);
    for(int i = 1; i <= n; i++) {
        f[i] = min(a[i], ans);
        k -= min(a[i], ans);
    }
    // cout << ans << '\n';
    for(int i = 1; i <= n && k < 0; i++) {
        f[i] -= (a[i] > ans);
        k += (a[i] > ans);
    }
    for(int i = 1; i <= n; i++) 
        cout << f[i] << " ";
}

void init() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], arr += a[i];
}

#define task "SHARE"
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