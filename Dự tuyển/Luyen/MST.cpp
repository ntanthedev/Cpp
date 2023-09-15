#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

template <typename T> inline void read (T &x) {
    bool b = 0;
    char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while (isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if (b) {
        x=-x;
    }
}

typedef long long ll;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, Q, w[N], t, totalWeight = 0;

struct Edge {
    int u, v, c;
    Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c){};
};

struct Dsu {
    vector<int> par;

    void init(int n) {
        par.resize(n + 5, 0);
        for(int i = 1; i <= n; i++)
            par[i] = i;
    }

    int find(int u) {
        if(par[u] == u)
            return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v)
            return false;
        par[v] = u;
        return true;
    }
} dsu;

vector<Edge> edges;

void sub1() {
    while(Q--) {
        cin >> t;
        edges.clear(); totalWeight = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) 
                if(i != j)
                    edges.pb({i, j, w[i] * w[j] + t * (w[i] + w[j])});
        dsu.init(n);
        sort(edges.begin(), edges.end(), [](Edge& x, Edge& y) { return x.c < y.c; });
        for(auto e: edges) {
            if(!dsu.join(e.u, e.v))
                continue;
            totalWeight += e.c;
        }
        cout << totalWeight << ' ';

    }
}

void solve() {
    if(n <= 1e3)
        sub1();
}           

void init() {
    read(n), read(Q);
    for(int i = 1; i <= n; i++) 
        read(w[i]);
}

#define task "MST"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}