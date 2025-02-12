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

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll sqr(ll x) {
    return x * x;
}

ll modd(ll x, ll n, ll m) {
    if(n == 0)
        return 1;
    ll t = modd(x, n/2, m)%m;
    if(n & 1) 
        return (x%m * (t * t)%m)%m;
    else 
        return (t * t)%m;
}

long long POWER(long long x, long long n, long long m) {
    if(n == 0) return 1;
    long long temp = POWER(x, n / 2, m) % m;

    if(n & 1) {
        return ((temp * temp) % m * x % m) % m;
    }else {
        return (temp * temp) % m;
    }
}

// void solve() {
    
// }

void init() {
    ll x, m, n;
    while(cin >> x >> n >> m)
        cout << POWER(x, n, m) << '\n';
}

#define task "POWER2"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    // cin >> test_case;
    while(test_case--) {
        init();
        // solve();
    }
    cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}