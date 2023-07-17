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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = 1e6+10;
const ll MOD = 1e9+7;


ll tohop(ll x, ll y) {
    if(x < y) return 0;
    if(x == y) return 1;
    y = max(y, x - y);
    ll t1 = 1, t2 = 1;
    for(int i = 1; i <= x-y; i++)
        t1 *= i;
    for(int i = y+1; i <= x; i++)
        t2 *= i;
    return (t2/t1);
}

ll n, a[N], k, ans = 0;

void solve() {
    sort(a+1, a+1+n);
    for(int i = k; i <= n; i++) {
        ans += (a[i]%MOD * tohop(i-1, k-1)%MOD)%MOD;
        ans %= MOD;
    }
    cout << ans%MOD;
}

void init() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}
#define task "PHANTHUONG"
int32_t main() {
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
}