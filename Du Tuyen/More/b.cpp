//problem "b"
//created in 00:05:32 - Fri 14/06/2024

#include<bits/stdc++.h>

using namespace std;


int f[20][2];
vector<int> a;

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

int dp(int i, bool ok) {
    if(i >= a.size())
        return 0;
    if(f[i][ok] != -1)
        return f[i][ok];
    f[i][ok] = 0;
    for(int j = 0; j <= (ok ? 9 : a[i]); j++)
        f[i][ok] += dp(i + 1, (ok || j < a[i])) + j;
    return f[i][ok];
}

int cal(int x) {

    a.clear(); 

    while(x > 0) {
        a.push_back(x % 10);
        x /= 10;
    }
    reverse(a.begin(), a.end());
    dbg(a)
    memset(f, -1, sizeof(f));

    return dp(0, 0);
}


int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    cout << cal(n);    
}