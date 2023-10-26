#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

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
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll m, n, k, s;
vll D;
vi city;
bool P[N];

struct Edge {
    ll v, w;
};

vector<Edge> E[N];
struct Node {
    ll u, d;
};

struct cmp {
    bool operator() (Node a, Node b) {
        return a.d > b.d;
    }
};

bool cmpcity(int a, int b) {
    return D[a] < D[b] || (D[a] == D[b] && a < b);
}

void solve() {
    D.resize(n+1, INT_MAX);
    memset(P, false, sizeof(P));
    D[s] = 0;
    priority_queue<Node, vector<Node>, cmp> h;
    h.push({s, D[s]});

    while(!h.empty()) {
        Node x = h.top();
        h.pop();

        ll u = x.u;
        if(P[u])
            continue;
        P[u] = true;
        for(int i = 0; i < E[u].size(); i++) {
            ll v = E[u][i].v;
            ll w = E[u][i].w;

            if(D[v] > D[u] + w) {
                D[v] = D[u]+w;
                h.push({v, D[v]});
            }
        }
    }
    
    sort(all(city), cmpcity);
    for(int i = 0; i < city.size(); i++) {
        cout << city[i] << " " << D[city[i]] << '\n';
    }
}

void init() {
    cin >> n >> m >> k >> s;
    for(int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        city.pb(x);
    }
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].pb({v, w});
        E[v].pb({u, w});
    }
}

#define task "OLYMPIC"
int32_t main() {
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