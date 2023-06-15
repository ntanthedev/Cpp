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

template <typename T> inline void read (T &x) {
    bool b = 0;
    char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while (isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if (b) {
        x=-x;
    }
}

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 3e5+10;
const ll MOD = 1e9+7;
int del[N], M[N], par[N], d[N];
int n, m, ans = 0;
set<int> f[N];
bool flag = 0;
void delet(int u){
    if(del[u]){
        return;
    }
    del[u] = 1;
    M[u] = 0; 
    for(auto i : f[u]){
        delet(i);
        //f[u].erase(i);
    }
}
void nhay(int u){
    if(del[u]){
        flag = true;
        return;
    }
    if(M[u] == 1 && del[u] == 0)
        return;
    
    int v = par[u];
    while(*f[v].begin() < u && !f[v].empty()){
        delet(*f[v].begin());
        f[v].erase(*f[v].begin());
    }
    nhay(v);
    M[u] = 1;
}
void solve(){
    for(int i = 1; i <= m; i++){
        nhay(d[i]);
        if(flag){
            cout << ans;
            return ;
        }
        ans++;
    }
    cout << ans;
}

void init(){
    read(n), read(m);
    for(int i = 1; i < n; i++){
        int u, v;
        read(u), read(v);
        f[u].insert(v);
        par[v] = u;
    }
    for(int i = 1; i <= m; i++)
        read(d[i]);
    M[1] = 1;
}
#define task ""
int32_t main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        init();
        solve();
    }
}