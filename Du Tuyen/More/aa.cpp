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

ll n, a[N], b[N], c[N], m, l, r;

void solve() {
    a[0] = LLONG_MAX;
    a[n + 1] = LLONG_MAX;
    for(int i = 2; i <= n; i++) {
        if(abs(a[i - 1] - a[i]) >= abs(a[i - 1]-a[i - 2]))
            b[i] = b[i-1] + a[i] - a[i - 1];
        else
            b[i] = b[i-1] + 1;
    }
    for(int i = n - 1; i >= 1; i--) {
        if(abs(a[i + 1] - a[i]) >= abs(a[i + 2] - a[i + 1]))
            c[i] = c[i+1] + a[i + 1] - a[i];
        else
            c[i] = c[i+1] + 1;
    }
    cin >> m;
    while(m--) {
        cin >> l >> r;
        if(l <= r)
            cout << b[r] - b[l];
        else 
            cout << c[r] - c[l];
        cout << '\n';
    }
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

#define task "aa"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}