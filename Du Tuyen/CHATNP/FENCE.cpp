#include<bits/stdc++.h>


const long long N = 1e5+9;
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

ll n, k;
ll a[N];

bool check(ll x) {
    ll kk = k;
    for(int i = 1; i < n; ++i) {
        ll t = (a[i + 1] - a[i])/x;
        kk -= t;
        if((a[i+1] - a[i])%x == 0) kk++;
        // if(x == 2) cout << "kk: " << kk << " i: " << i << '\n';
        if(kk < 0) return false;
    }
    return (kk >= 0);
}
/*
3
0 2 5 7 9
*/
void solve() {
    sort(a+1, a+1+n);
    if(k == 0) return cout << a[n] - a[1], void() ;
    ll l = 1, r = 1e9, ans = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }
    // cout << check(2) << '\n';
    cout << ans;
}

#define task "FENCE"
signed main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    solve();
}
