//problem "b"
//created in 07:14:32 - Sat 15/06/2024

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

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

ll f[20][2];
vector<ll> a;

ll dp(ll i, bool ok) {
    if(i >= a.size())
        return 0;
    if(f[i][ok] != -1)
        return f[i][ok];
    f[i][ok] = 0;
    for(ll j = 0; j <= (ok ? 9 : a[i]); j++)
        f[i][ok] += dp(i + 1, (ok | j < a[i])) + 
        j * ((i != (a.size() - 2) && (ok | j < a[i])) ? 10 : a[i + 1] + 1);
    return f[i][ok];
}

ll cal(ll x) {
    if(x < 0)
        return 0;

    a.clear(); 

    while(x > 0) {
        a.push_back(x % 10);
        x /= 10;
    }

    reverse(a.begin(), a.end());
    a.push_back(0);
    dbg(a)
    memset(f, -1, sizeof(f));

    return dp(0, 0);
}


int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll n;
    cin >> n;

    cout << cal(n) << '\n';

    for(int i = 0; i <= 1; i++)
        for(int j = 0; j <= 1; j++)
            cout << "f[" << i << "][" << j << "]: " << f[i][j] << '\n';
}