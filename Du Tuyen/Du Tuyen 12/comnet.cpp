//Written by: ntannn_
//created in 08:55:16 - Fri 09/08/2024
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

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

int n, m;
set<ii> adj[N];
bool check_sub1 = 1;
int lab[N], cnt = n;

struct Edge {
    int u, v, w;

    Edge (int _u, int _v, int _w) {
        u = _u, v = _v, w = _w;
    }; 

    bool operator < (Edge x) {
        return w < x.w;
    }
};

int find_lab(int x) {
    return lab[x] < 0 ? x : lab[x] = find_lab(lab[x]);
}

void merge_lab(int x, int y) {
    x = find_lab(x);
    y = find_lab(y);

    if(x != y) {
        cnt--;
        if(lab[x] > lab[y])
            swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
    }
}

void sub1() {
    cout << cnt - 1; 
}

void sub2() {

}

void solve() {
    cin >> n >> m;
    memset(lab, -1, sizeof(lab));
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        auto t = adj[u].lower_bound({v, 0LL});
        if(t->se != v) {
            adj[u].insert({v, w});
            adj[v].insert({u, w});
        }
        else {
            int new_w = min(t->se, w);
            adj[u].erase(t);
            adj[u].insert({v, new_w});
            t = adj[v].lower_bound({u, 0LL});
            adj[v].erase(t);
            adj[v].insert({u, new_w});
        }
        merge_lab(u, v);
        if(w != 1) 
            check_sub1 = 0;
    }

    if(check_sub1) 
        sub1();
    else 
        sub2();
}

#define task "comnet"
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
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}