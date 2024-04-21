//Written by: ntannn_
//created in 14:37:03 - Sun 21/04/2024
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

ll n, m, block_size;
ll a[N], ans[N], cnt[N];
vector<query> q;

struct query {
    int id, l, r;
};

bool cmp(query x, query y) {
    return mp(x.l / block_size, x.r) < mp(y.l / block_size, y.r);
}

void solve() {
    sort(all(q));

    int curl = 0, curr = -1;

    for(auto &i : q) {
        
    }
}

void init() {
    cin >> n >> m; block_size = sqrt(n);

    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    for(int i = 1, l, r; i <= n; i++) {
        cin >> l >> r;
        q.eb(i, l, r);
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