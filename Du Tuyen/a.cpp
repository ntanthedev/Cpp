//Written by: ntannn_
//created in 19:42:15 - Thu 20/06/2024
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

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll n, Q, a[N];
vector<ll> s;
vector<pair<int, pll>> q;

void solve() {
    
}

void init() {
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s.eb(a[i]);
    }
    for(int i = 1; i <= Q; i++) {
        char c;
        ll x, y;
        cin >> c >> x >> y;
        q.eb((c == '!' ? 1 : 2), x, y);
    }
}

#define task "a"
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