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

ll a, b, c, n;

ll lcm(ll x, ll y) {
    return x*y/__gcd(x, y);
}

ll sum(ll x, ll y, ll z, ll s) {
    return (s/x) + (s/y) + (s/z) - (s/lcm(x,y)) - (s/lcm(x, z))  - (s/lcm(y,z)) + (s/lcm(lcm(x,y),z));
}

bool check(ll s) { 
    ll res = sum(a, b, c, s) - sum(lcm(a, b), lcm(b, c), lcm(a, c), s);
    return (res >= n);
}

void solve() {
    ll l = 1, r = 1e18, ans, mid;
    while(l <= r) { 
        mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else 
            l = mid+1;
    }
    cout << ans;
}

void init() {
    cin >> a >> b >> c >> n;
}

#define task "FINDMUL"
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