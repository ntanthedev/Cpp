//Written by: ntannn_
//created in 15:07:02 - Sat 16/03/2024
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

int n, k;
ll ans = 0, a[N], s[N], r[N], l[N];

void solve() {
    r[n-k+2] = INT_MAX;
    for(int i = n-k+1; i >= 1; i--) {
        r[i] = min(r[i+1], s[i+k-1] - s[i-1]);
    }
    l[k-1] = 0;
    for(int i = k; i <= n; i++) {
        l[i] = max(l[i-1], s[i] - s[i-k]);
    }
    for(int i = k; i <= n-k; i++) {
        ans = max(ans, l[i] - r[i+1]);
    }
    r[n-k+2] = 0;
    for(int i = n-k+1; i >= 1; i--) {
        r[i] = max(r[i+1], s[i+k-1] - s[i-1]);
    }
    l[k-1] = INT_MAX;
    for(int i = k; i <= n; i++) {
        l[i] = min(l[i-1], s[i] - s[i-k]);
    }
    for(int i = k+1; i <= n-k+1; i++) {
        ans = max(ans, r[i] - l[i-1]);
    }
    cout << ans;
}

void init() {
    cin >> n >> k;
    s[0] = 0;
    for(int i = 1; i <= n; i++) 
        cin >> a[i], s[i] = s[i-1] + a[i];
}

#define task "DAXANH"
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