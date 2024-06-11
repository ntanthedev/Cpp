//Written by: ntannn_
//created in 14:20:20 - Fri 17/05/2024
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

ll n, a[N], f[N], ans = 0;
map<ll, ll> m;

void solve() {
    cout << ans;
}

void init() {
    cin >> n >> a[1];
    f[1] = a[1] % 7;
    m[f[1]]++;
    for(ll res = a[1], i = 2; i <= n; i++) {
        cin >> a[i];
        f[i] = (a[i] * res) % 7;
        ans += (a[i] % 7 == 0);
        ans += m[f[i]];
        m[f[i]]++;
        res += a[i]; res %= 7;
        cout << res << " " << f[i] << '\n';
    }
}

#define task "DIV7"
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