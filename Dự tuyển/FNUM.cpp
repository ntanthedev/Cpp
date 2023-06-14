#include<bits/stdc++.h>
#define fi first
#define se second
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
ll a, b, n;

//----------------------------

void solve(){
    if(a > b)
        swap(a, b);
    ll l ;;
    ll i = 1, f = 0, t;
    while(true){
        if(i%a == 0 || i%b == 0)
            ++f;
        if(i%a == 0 && i%b == 0){
            t = f;
            l = i;
            break;
        }
        i++;
    }
    ll m = n/t;
    f = m*t;
    i = m*l;
    while(true){ 
        if(f == n){
            cout<<i;
            return;
        }        
        if(i%a == 0 || i%b == 0)
            ++f;     
        i++;
    }

}

void init(){
    read(a), read(b), read(n);

}
//-----TASK----------
#define task "FNUM"
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