#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
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
ll Q, a, b;

//----------------------------
ll sum(ll x){
    if(x == 0)
        return 0;
    if(x == 1)
        return 1;
    return ((x+1)/2)*((x+1)/2) + sum(x/2);
}
void solve(){
    ll res = 0;    
    ll reso = 0, rese = 0;
    //reso = ((b+1)/2)*((b+1)/2) - (a/2)*(a/2);
    rese = sum(b) - sum(a-1);
    //cout << reso <<" " << rese << " ";
    cout <<  rese <<'\n';  
}
 
void init(){
    cin >> Q;
    while(Q--){
        cin >> a >> b;
        solve();
    }
}
//-----TASK----------
#define task ""
//-------------------
int32_t main(){
    //---------------------------------
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".out","w",stdout);
        freopen(task".inp","r",stdin);
    }
    //---------------------------------
    init();
    //solve();
}