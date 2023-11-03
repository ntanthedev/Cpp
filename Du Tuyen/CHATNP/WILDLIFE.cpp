#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll m, n, t[N];
vii f[N];
ii trace[N];

bool bfs(int mid) {
    map<ll, bool> M; 
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto i : f[u]) {
            if(!M[i.fi] && abs(t[i.fi] - t[u]) <= mid) {
                q.push(i.fi);
                M[i.fi] = true;
            }
        }
    }
    return M[n];
}

void out(ll ans) {
    queue<int> q;
    q.push(1);
    trace[1] = mp(-1, -1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto i : f[u]) {
            if(trace[i.fi].fi == 0 && abs(t[i.fi] - t[u]) <= ans) {
                q.push(i.fi); 
                trace[i.fi] = f[u][i.fi];
            }
        }
    }
    vector<int> as;
    ll t = n;
    while(t != 0) {
        as.pb(t); 
        t = trace[t];
    }
    reverse(as.begin(), as.end());
    cout << as.size() << '\n';
    for(auto i : as)
        cout << i << " ";
}

void solve() {
    ll l = 1, r = n, mid, ans;
    while(l <= r) {
        mid = (l + r) / 2;
        if(bfs(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else 
            l = mid + 1;
    }    
    
}

void init() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> t[i];
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        f[u].eb(mp(v, i));
        f[v].eb(mp(u, i));
    }
}

#define task "WILDLIFE"
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
    //cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}