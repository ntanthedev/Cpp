#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
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

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6+10;
const ll MOD = 1e9+7;

bool is_prime(int x)
{
    for(int i = 2 ; i * i <= x ; i++)
        if(x%i == 0)
            return 0;
    return 1;
}
//----------------------------
ll n, k;
ll par[N];
//----------------------------
ll powmod(ll x, ll y){
    ll res = 1;
    x = x%MOD;
    for(int i = 1; i <= y; i++){
        res *= x;
        res = res%MOD;
    }
    return res;
}
int find_sets(int x){
    return par[x] < 0 ? x : par[x] = find_sets(par[x]);
}
void make_sets(int x){
    par[x] = -1;
}
void unions_set(int a, int b){
    a = find_sets(a);
    b = find_sets(b);

    if(par[a] > par[b])
        swap(a, b);
    par[a] += par[b];
    par[b] = a;
}
void solve(){
    ll res = powmod(n, k);
    for(int i = 1; i <= n; i++){
        if(par[i] < 0){
            ll t = -(par[i]);
            t = powmod(t, k);
            res = (res - t + MOD)%MOD;
        }
    }
    cout << res;
}

void init(){
    read(n), read(k);
    for(int i = 1; i <= n; i++)
        make_sets(i);
    for(int i = 1; i < n; i++){
        ll u, v, w;
        read(u), read(v), read(w);
        if(!w)
            unions_set(u, v);
    }
}
//-----TASK----------
#define task "TASK"
//-------------------
int32_t main(){
    //---------------------------------
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    //---------------------------------
    init();
    solve();
}
/*

*/