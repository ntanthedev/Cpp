//Written by: ntannn_
//created in 15:03:58 - Mon 11/03/2024
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

struct Less {
    bool operator () (ll x, ll y) {
        return x > y;
    };
};

ll n, m, a[N], s = 0;
priority_queue<ll, vll, Less> q;

void solve() {
    for(int i = 1; i <= m; ++i)
        q.push(0);
    for(int i = 1; i <= n; i++) {
        ll t = q.top();
        q.pop();
        q.push(t + a[i]);
    }
    for(int i = 1; i < m; i++)
        q.pop();
    cout << q.top();
}

void init() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i], s += a[i];
}

#define task "bai4"
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