//Written by: ntannn_
//created in 18:09:10 - Fri 15/03/2024
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

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

int n, m;
ll a[N], b[N], S = 0, E = 0, Q = 0;
map<ll, ll> A, B;
vector<pll> ca, cb;

void solve() {
    ll temp = 0;
    for(auto i : A) {
        ca.eb(i.fi, i.se + temp);
        temp += i.se;
    }
    temp = 0;
    for(auto i : B) {
        cb.eb(i.fi, i.se + temp);
        temp += i.se;
    }
    dbg(A) dbg(B) dbg(ca) dbg(cb)
    for(auto i : B) {
        auto it = lower_bound(all(ca), mp(i.fi, 0LL));
        if(it == ca.begin())
            continue;
        S += i.se * --it->se;
        dbg(i) dbg(*it)
    }
    for(auto i : A) {
        if(B[i.fi] != 0)
            E += i.se * B[i.fi];
    }
    for(auto i : A) {
        auto it = --lower_bound(all(cb), mp(i.fi, 0LL));
        if(it == cb.begin())
            continue;
        Q += i.se * --it->se;
    }
    cout << S << " " << E << " " << Q;
}

void init() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++) { 
        cin >> a[i];
        a[i] += a[i-1];
        for(int j = i; j >= 1; j--) {
            ll s = a[i] - a[j-1];
            A[s]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] += b[i-1];
        for(int j = i; j >= 1; j--) {
            ll s = b[i] - b[j-1];
            B[s]++;
        }
    }
}

#define task "SEQ2SC"
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