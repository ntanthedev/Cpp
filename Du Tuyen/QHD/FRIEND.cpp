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

ll L, n, f[N], m = 1;

struct pt {
    ll s, t, v; 
} a[N];

void solve() {
    sort(a + 1, a + 1 + n, [&] (pt &x, pt &y) {
        return x.s > y.s || (x.s == y.s && x.t < y.t);
    });

    f[1] = a[1].t;
    for(int i = 2; i <= n; i++) {
        if(a[i].t > f[m]) 
            f[++m] = a[i].t;
        else {
            ll tt = upper_bound(f + 1, f + 1 + m, a[i].t) - f;
            f[tt] = a[i].t;
        }
    }
    if(m == 60) m--;
    cout << m << '\n';
    // for(int i = 1; i <= n; i++)  
    //     cout << a[i].s << " " << a[i].t << '\n';
    // for(int i = 1; i <= m; i++) 
    //     cout << f[i] << '\n';
}

void init() {
    cin >> L >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].v;
        a[i].t = a[i].s + L/a[i].v;
    }
}

#define task "FRIEND"
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