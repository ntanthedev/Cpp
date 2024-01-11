#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define w first
#define v second
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
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, W, gmax = 0;
pll a[41];
vector<pll> ans, tempp;

void QL1(int i = 1, pll s = {0, 0}) {
    if(i > n/2) {
        tempp.eb(s);
        return;
    }
    for(int j = 0; j <= 1; j++) {
        if(s.w + a[i].w*j > W) continue;
        QL1(i+1, {s.w + a[i].w, s.v + a[i].v});
    }
}

void check(pll s) {
    ll t = upper_bound(all(ans), s) - ans.begin() - 1;
    gmax = max(gmax, ans[t].v + s.v);
}

void QL2(int i = n/2 + 1, pll s = {0, 0}) {
    if(i > n) {
        check(s);
        return;
    }
    for(int j = 0; j <= 1; j++) {
        if(s.w + a[i].w*j > W) continue;
        QL2(i + 1, {s.w + a[i].w*j, s.v + a[i].w*j});    
    }
}

void solve() {
    QL1();
    sort(all(tempp));
    ans.eb(tempp[0]);
    for(int i = 1; i < tempp.size(); i++) {
        ans.eb(tempp[i]);
        if(tempp[i].w > tempp[i-1].w && tempp[i].v <= tempp[i-1].v)
            ans.pop_back();
    }
    dbg(tempp)
    dbg(ans)
    QL2();
    cout << gmax;
}

void init() {
    cin >> n >> W;
    for(int i = 1; i <= n; i++) 
        cin >> a[i].w >> a[i].v;
}

#define task "a"
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
    cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}