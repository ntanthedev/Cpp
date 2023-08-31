#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

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

ll ans = 0, n, m, f[N];

ll tohop(ll n, ll k) {
    ll t1 = 1, t2 = 1;
    for(ll i = k+1; i <= n; i = i+1) {
        t1 *= i;
    }
    for(ll i = 1; i <= n-k; i += 1)
        t2 *= i;
    return t1/t2;
}

void solve() {
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = ((n-1)%MOD * f[i-1]%MOD + f[i-2]%MOD)%MOD;
    }
    for(int k = 0; k <= m; k++) {
        ans += tohop(n, k) * f[n-k];
    }
    cout << ans;
}

void init() {
    cin >> n >> m;
}

#define task "HAT2"
int32_t main() {
    cin.tie(nullptr);
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
