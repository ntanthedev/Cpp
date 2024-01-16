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
vector<pll> p1, p2, temp;

void QL1(int i = 1, pll s = {0, 0}) {
    if(i > n/2) {
        temp.eb(s);
        return;
    }
    for(int j = 0; j <= 1; j++) {
        if(s.w + a[i].w*j > W) continue;
        QL1(i+1, {s.w + a[i].w*j, s.v + a[i].v*j});
    }
}

// void check(pll s) {
//     dbg(s)
//     auto t = upper_bound(all(ans), mp(W - s.w, LLONG_MAX)) - ans.begin();
//     dbg(t)
//     t--;
//     gmax = max(gmax, ans[t].v + s.v);
//     dbg(gmax)
// }

void QL2(int i = n/2 + 1, pll s = {0, 0}) {
    if(i > n) {
        temp.eb(s);
        return;
    }
    for(int j = 0; j <= 1; j++) {
        if(s.w + a[i].w*j > W) continue;
        QL2(i + 1, {s.w + a[i].w*j, s.v + a[i].v*j});    
    }
}

void solve() {
    QL1();
    dbg(temp)
    sort(all(temp), [&] (auto x, auto y) {
        return x.w < y.w || (x.w == y.w && x.v > y.v);
    });
    dbg(temp)
    p1.pb(temp[0]);
    for(int i = 1; i < temp.size(); i++) {
        if(temp[i].v > p1.back().v)
            p1.pb(temp[i]);
    }
    temp.clear();
    QL2();
    dbg(temp)
    sort(all(temp), [&] (auto x, auto y) {
        return x.w < y.w || (x.w == y.w && x.v > y.v);
    });
    dbg(temp)
    p2.pb(temp[0]);
    for(int i = 1; i < temp.size(); i++) {
        if(temp[i].v > p2.back().v)
            p2.pb(temp[i]);
    }
    dbg(p1)
    dbg(p2)
    if(p1.size() > p2.size())
        swap(p1, p2);
    for(auto i : p1) {
        auto t = upper_bound(all(p2), mp(W - i.w, LLONG_MAX)) - p2.begin() - 1;
        if(i.w + p2[t].w <= W)
            gmax = max(gmax, i.v + p2[t].v);
    }
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
