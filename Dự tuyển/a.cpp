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
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e3+10;
const ll MOD = 1e9+7;

ll n;
vii f;
queue<ll> q;
umib M;

void solve(ll x, ll y) {
    M.clear();
    while(!q.empty()) q.pop();
    bool flag = 0;
    q.push(x);
    M[x] = 1;
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        if(u == y) {
            flag = 1;
            break;
        }
        for(ll i = 1; i < f.size(); i++) {
            if(!M[i]) {
                if((f[u].fi > f[i].fi && f[u].fi < f[i].se) || (f[i].fi > f[u].fi && f[i].fi < f[u].se)) {
                    q.push(i);
                    M[i] = 1;
                }
            }
        }
    }
    if(flag)
        cout << "YES\n";
    else 
        cout << "NO\n";
}

void init() {
    cin >> n;
    f.reserve(n+1);
    f.pb(mp(0, 0));
    ll t, u, v;
    for(int i = 1; i <= n; i++) {
        cin >> t >> u >> v;
        if(t == 1) 
            f.eb(mp(u, v));
        else 
            solve(u, v);
        dbg(f);
    }
}
#define task ""
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    cin >> test_case;
    while(test_case--) {
        init();
        //solve();
    }
}