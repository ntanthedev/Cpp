//Written by: ntannn_
//created in 14:44:43 - Mon 11/03/2024
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

ll n, a[N];
vector<int> b, c;

void solve() {
    b.pb(a[1]);
    for(int i = 2; i <= n; i++) {
        if(a[i] < b.front())
            b[0] = a[i];
        else if(a[i] > b.back())
            b.pb(a[i]);
        else {
            int t = lower_bound(all(b), a[i]) - b.begin();
            b[t] = a[i];
        }
    }
    c.pb(a[1]);
    for(int i = n-1; i >= 1; i--) {
        if(a[i] < c.front())
            c[0] = a[i];
        else if(a[i] > c.back())
            c.pb(a[i]);
        else {
            int t = lower_bound(all(c), a[i]) - c.begin();
            c[t] = a[i];
        }
    }
    cout << min(n - b.size(), n - c.size());
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

#define task "TREE"
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