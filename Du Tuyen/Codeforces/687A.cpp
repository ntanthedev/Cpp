//Written by: ntannn_
//created in 13:56:19 - Mon 11/03/2024
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;

int n, m, M[N];
vi f[N];
vi a, b;

void dfs(int x, int c) {
    if(!c)
        a.pb(x);
    else 
        b.pb(x);
    for(auto i : f[x]) {
        if(M[i] == -1) {
            M[i] = 1 - c;
            dfs(i, 1 - c);
        }
        else if(M[i] == c) {
            cout << -1;
            exit(0);
        }
    }
}

void solve() {
    for(int i = 1; i <= n; i++) {
        if(M[i] == -1 && !f[i].empty()) {
            M[i] = 1;
            dfs(i, 1);
        }
    }

    cout << a.size() << '\n';
    for(auto i : a)
        cout << i << " " ;
    cout << '\n' << b.size() << '\n';
    for(auto i : b)
        cout << i << " ";
}

void init() {
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        f[u].pb(v);
        f[v].pb(u);
    }
    memset(M, -1, sizeof(M));
    // for(int i = 1; i <= n; i++) {
    //     dbg(f[i]);
    // }
    // return;    
}

#define task "687A"
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