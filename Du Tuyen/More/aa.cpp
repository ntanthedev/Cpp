//Written by: ntannn_
//created in 08:28:08 - Sat 09/03/2024
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
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

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;

ll n, m, k, amin = 0, amax = 0; 
vi vt;
vll D;
vii f[N];
bool checksub = 1;
vector<bool> cc;

void sub13() {
    vll D(n + 1, 0);
    int s = vt[1], t = vt[k];
    queue<int> q;
    q.push(t);
    D[t] = 0;
    
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto i : f[u]) {
            if(D[i.fi] == 0 && i.fi != t) { 
                q.push(i.fi);
                D[i.fi] = D[u] + 1;
            }
        }
    }
    // for(auto i : D)
    //     cout << i << " " ; cout << '\n';
    cc.resize(n + 1, false);
    for(int i = 1; i < k; i++) {
        ll Dmin = INT_MAX, cnt = 0;
        for(auto j : f[i]) Dmin = min(Dmin, D[j.fi]);
        for(auto j : f[i]) cnt += (D[j.fi] == Dmin);
        if(D[vt[i + 1]] == Dmin)
            amax += cnt-1;
        else 
            amax += cnt, amin += cnt;
    }
    cout << amin << " " << amax;
}

struct Node {
    int u;
    ll D_u;
};

struct cmp {
    bool operator() (Node a, Node b) {
        return a.D_u > b.D_u;
    }
};

vi trace_path(vector<int> &trace, int S, int u) {
    if (u != S && trace[u] == -1) return vector<int>(0);
    vi path;
    while (u != -1) { 
        path.push_back(u);
        u = trace[u];
    }
    // reverse(path.begin(), path.end());
    return path;
}

void sub4() {
    vector<ll> D(n + 1, INT_MAX);
    vi trace(n + 1, -1);
    vector<bool> P(n + 1, 0);
    int s = vt[1], t = vt[k];
    D[t] = 0;
    priority_queue<Node, vector<Node>, cmp> h;
    h.push({t, D[t]});
    while(!h.empty()) {
        Node x = h.top();
        h.pop();

        int u = x.u;
        if(P[u])
            continue;
        
        P[u] = true;

        for(auto e : f[u]) {
            auto [v, w] = e;

            if(D[v] > D[u] + w) {
                D[v] = D[u] + w;
                h.push({v, D[v]});
                trace[v] = u;
            }
        }
    }
    // for(int i = 1; i <= n; i++)
    //     cout << D[i] << " "; cout << '\n';
    // vi path = trace_path(trace, t, s);
    // for(auto i : path)
    //     cout << i << " "; cout << '\n';
    for(int i = 1; i < k; i++) {
        ll Dmin = INT_MAX, cnt = 0;
        ii next;
        for(auto j : f[vt[i]]) {
            cnt += (D[j.fi] + j.se == D[vt[i]]);
            if(vt[i + 1] == j.fi)
                next = j;
        }
        if(D[vt[i + 1]] + next.se == D[vt[i]])
            amax += cnt-1;
        else 
            amax += cnt, amin += cnt;   
    }
    cout << amin << " " << amax;
}

void solve() {
    if(checksub)
        sub13();
    else  
        sub4();
    
}

void init() {
    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        f[u].eb(v, w);
        f[v].eb(u, w);
        if(w != 1)
            checksub = 0;
    }
    cin >> k;
    vt.resize(k + 1);
    for(int i = 1; i <= k; i++)
        cin >> vt[i];    
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
