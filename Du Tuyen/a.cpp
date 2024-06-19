// Written by: ntannn_
// created in 18:26:38 - Wed 19/06/2024
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define x first
#define w second
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

ll n, k, ans = 0, t, s[N];
pll a[N];

void solve() {
    sort(a + 1, a + 1 + n);

    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i].w;
    
    ll i = lower_bound(a + 1, a + 1 + n, mp(t - k, 0LL)) - a;
    
    while(a[i].x <= t) {
        ll f = upper_bound(a + 1, a + 1 + n, mp(a[i].x + k - (t - a[i].x), 0LL)) - a - 1;
        ans = max(ans, s[f] - s[i - 1]);
    
        f = upper_bound(a + 1, a + 1 + n, mp(a[i].x + (k - (t - a[i].x)) / 2, 0LL)) - a - 1;
        ans = max(ans, s[f] - s[i - 1]);
    
        i++;
    }

    cout << ans;
}

void init() {
    cin >> n >> t >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].w;
}

#define task "MARIO"
signed main() {
    cin.tie(NULL);
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
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}