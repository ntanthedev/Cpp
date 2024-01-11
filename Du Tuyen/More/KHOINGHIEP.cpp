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

const int N = 2e5+10;
const ll MOD = 1e9+7;

ll n;
map<ll, bool> M;

struct pt {
    ll fi, se, vt;
};

struct Less {
    bool operator () (pt x, pt y) {
        return x.fi > y.fi;
    }
};

struct More {
    bool operator () (pt x, pt y) {
        return x.se > y.se;
    }
};

priority_queue<pt, vector<pt>, Less> q1;
priority_queue<pt, vector<pt>, More> q2;

pt a[N];

void solve() {
    // cout << "q1:\n";
    // while(!q1.empty()) {
    //     cout << q1.top().fi << " " << q1.top().se << " " << q1.top().vt << '\n';
    //     q1.pop();
    // }
    // cout << "q2:\n";
    // while(!q2.empty()) {
    //     cout << q2.top().fi << " " << q2.top().se << " " << q2.top().vt << '\n';
    //     q2.pop();
    // }
    // return;
    ll d = 0, res = 0;
    while(!q1.empty() && !q2.empty()) {
        while(M[q1.top().vt])
            q1.pop();
        while(M[q2.top().vt])
            q2.pop();
        if(d >= q1.top().fi) {   
            d++;
            M[q1.top().vt] = true; 
            q1.pop();
        }
        else {
            res += q2.top().se;
            M[q2.top().vt] = true;
            q2.pop();
        }
        // while(M[q1.top().vt])
        //     q1.pop();
        // while(M[q2.top().vt])
        //     q2.pop();
    }
    cout << res;
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        a[i].vt = i;
        q1.push(a[i]);
        q2.push(a[i]);
    }
}

#define task "KHOINGHIEP"
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