#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
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

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6+10;
const ll MOD = 1e9+7;

int n, l, r;
vector<string> a;
int x[7], sumofsize = 0;
string ans;
vector<string> dp;

void check() {
    string s;
    for(int i = 0; i < n; i++) {
        if(x[i])
            s += a[i];
    }
    if(s > ans && s.size() >= l && s.size() <= r)
        ans = s;
}

void quaylui(int i) {
    for(int j = 0; j <= 1; j++) {
        x[i] = j;
        if(i == n-1)
            check();
        else 
            quaylui(i+1);
    }
}

void sub1() {
    ans = "0";
    quaylui(0);
    if(ans == "0")
        cout << -1;
    else 
        cout << ans;
    // dbg(a);
}

void sub2() {
    for(auto i : a)
        cout << i;  
}

void sub4() {
    dp.resize(n+1);
    dp[0] = a[0];
    for(int i = 1; i < n; i++) {
        dp[i] = a[i];
        for(int j = 0; j < i; j++) {
            string t = dp[j] + a[i];
            // cout << t << '\n';
            if(t > dp[i] && t.size() <= r)
                dp[i] = t; 
        }
    }
    string res = dp[0];
    for(int i = 1; i < n; i++) {
        if(dp[i].size() >= l && dp[i].size() <= r && dp[i] > res)
            res = dp[i];
        // cout << dp[i] << '\n';
    }
    if(res.size() >= l && res.size() <= r)
        cout << res;
    else 
        cout << -1;
}

void solve() {
    if(sumofsize < l)
        return cout << -1, void();
    sort(all(a));
    reverse(all(a));
    if(n <= 6)
        sub1();
    else if(n <= 100 && sumofsize >= l && sumofsize <= r) 
        sub2();
    else 
        sub4();
}

void init() {
    cin >> n >> l >> r;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sumofsize += a[i].size();
    }
}

#define task "PASS"
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
}