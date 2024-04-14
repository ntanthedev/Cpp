//Written by: ntannn_
//created in 14:05:52 - Sat 13/04/2024
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

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll n, s[N], sumarr = 0, smin[N];
double ans = 1e9;

void sub1() {
    for(int i = 2; i < n; i++) {
        for(int j = i; j < n; j++) {        
            ll t = sumarr - (s[j] - s[i-1]);
            ans = min(ans, double(t) / (n - (j - i + 1)));
        }
    }
    cout << fixed << setprecision(3) << ans;
}

void sub2() {
    ll gmax = 0, k = 0;
    for(int i = 2; i < n; i++) {
        if(s[i] - s[smin[i]] > gmax && smin[i] != 0)
            k = i - smin[i] + 1, gmax = s[i] - s[smin[i]];
    }
    cout << fixed << setprecision(3) << double(sumarr - gmax) / (n - k);     
}

void solve() {
    if(n <= 5e3)
        sub1();
    else 
        sub2();
}

void init() {
    cin >> n;
    s[0] = 0, smin[0] = 0;
    for(int i = 1; i <= n; i++) 
        cin >> s[i], s[i] += s[i - 1], smin[i] = (s[i] < s[smin[i - 1]] ? i : smin[i - 1]);
    sumarr = s[n];
}

#define task "DELSEG"
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