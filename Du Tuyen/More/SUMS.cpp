//template for some simple code by ntannn_
//created in 14:31:52 - Thu 25/01/2024
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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6 + 10;
const int NDP = 5e4;
const ll MOD = 1e9 + 7;

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

ll n, S, a[N], s[N];
vector<int> ans;
bool flag;
vector<ll> vt;
map<ll, vector<ll>> M;
map<ll, bool> M1;
vector<ll> L;
vector<ll> trace[NDP];

void ql1(int i = 1, ll res = 0) {
    if(flag) return;
    if(i > n) {
        if(res == S) {
            flag = 1;
            cout << "1\n";
            for(int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
        }
        return;
    }

    for(int j = 0; j <= 1; j++) {
        if(j) 
            ans.pb(a[i]);
        ql1(i+1, res + j * a[i]);
        if(j)
            ans.pop_back();
    }
}

void ql21(int i = 1, ll res = 0) {
    if(i > n/2) {
        M[res] = vt;
        M1[res] = true;
        return;
    }

    for(int j = 0; j <= 1; j++) {
        if(res + a[i] * j > S || res + a[i] * j + s[n] - s[i] < S)
            continue;
        if(j)
            vt.pb(a[i]);
        ql21(i + 1, res + a[i] * j);
        if(j)
            vt.pop_back();
    } 
}

void ql22(int i = n/2+1, ll res = 0) {
    if(flag)
        return;
    if(i > n) {
        ll w = S - res;
        if(M1[w]) {
            cout << 1 << '\n';
            dbg(w)
            dbg(M[w])
            dbg(vt)
            for(int j = 0; j < M[w].size(); j++)
                cout << M[w][j] << " ";
            for(int j = 0; j < vt.size(); j++)
                cout << vt[j] << " " ;
            flag = 1;
        }
        return;
    }
    for(int j = 0; j <= 1; j++) {
        if(j)
            vt.pb(a[i]);
        ql22(i+1, res + a[i] * j);
        if(j)
            vt.pop_back();
    }
}


void sub3() {
    L.resize(S + 1, 0);
    L[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int t = S; t >= a[i]; t--) {
            if(L[t] == 0 && L[t - a[i]] == 1) {
                L[t] = 1;
                trace[t] = trace[t - a[i]];
                trace[t].pb(a[i]);
            }
        }
    }
    if(L[S]) {
        cout << 1 << '\n';
        for(int i = 0; i < trace[S].size(); i++)
            cout << trace[S][i] << " ";
    }
    else 
        cout << -1;
}
void solve() {
    if(n <= 20) {
        flag = 0;
        ql1();
        if(!flag)
            cout << -1 << '\n';
        return;
    }
    else if(n <= 40) {
        flag = 0;
        ql21();
        vt.clear();
        ql22();
        if(!flag)
            cout << -1 << '\n';
        return;
    }
    else 
        sub3();
    
}

void init() {
    s[0] = 0;
    cin >> n >> S;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = a[i] + s[i-1];
    }
}

#define task "SUMS"
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