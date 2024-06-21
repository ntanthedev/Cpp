//Written by: ntannn_
//created in 19:42:15 - Thu 20/06/2024
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
#define int int64_t    

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

int n, Q, a[N], m = 0, tree[N];
vector<int> s;
map<int, int> pos;
vector<pair<int, ii>> q;

void update(int id, int l, int r, int u, int w) {
    if(u < l || r < u)
        return;
    if(l == r) {
        tree[id] += w;
        return;
    }
    int mid = (l + r) / 2;
    if(mid >= u)
        update(id * 2, l, mid, u, w);
    else 
        update(id * 2 + 1, mid + 1, r, u, w);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int query(int id, int l, int r, int u, int v) {
    if(v < l || u > r)
        return 0;
    if(u <= l && r <= v) 
        return tree[id];
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

void solve() {
    sort(all(s));
    s.resize(unique(all(s)) - s.begin());
    
    // cerr << "\x1b[31mstart debug: \n";
    // for(auto i : s) 
    //     cerr << i << " " ;
    // cerr << '\n';
    // cerr << "end of debug\e[39m \n";
    // exit(0);

    for(int i = 0; i < s.size(); i++) 
        pos[s[i]] = i + 1;
        // s[i] = i + 1;

    // cerr << "\x1b[31mstart debug: \n";
    // for(auto i : s) 
    //     cerr << i << " " ;
    // cerr << '\n';
    // cerr << "end of debug\e[39m \n";
    // exit(0);
    
    m = s.size();

    for(int i = 1; i <= n; i++) {
        // a[i] = pos[a[i]];
        update(1, 1, m, pos[a[i]], 1);
    }

    for(auto [c, p] : q) {
        auto [x, y] = p;
        if(c == 1) {
            update(1, 1, m, pos[a[x]], -1);
            update(1, 1, m, pos[y], 1);
            a[x] = y;
        }
        else {
            int l = *lower_bound(all(s), x);
            int r = *--upper_bound(all(s), y);
            cout << query(1, 1, m, pos[l], pos[r]) << '\n';
        }
    }
}

void init() {
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s.pb(a[i]);
    }
    for(int i = 1; i <= Q; i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c == '!') {
            q.pb(mp(1, mp(x, y)));
            s.pb(y);
        }
        else 
            q.pb(mp(2, mp(x, y)));
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