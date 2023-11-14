#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define w first
#define v second
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

ll n, m, gmax = 0, s[101];
pll a[101];
vll ans, res;

void solve(int i, ll kl, ll gt) {
    if(i > n) {
        if(gt > gmax) {
            ans = res;
            gmax = gt;
        }
        return;
    }
    for(int j = 0; j <= 1; ++j) {
        if(kl + j * a[i].w > m || gt + j * a[i].v + (s[n] - s[i]) <= gmax)
            continue;
        if(j)
            res.eb(i);
        solve(i + 1, kl + j * a[i].w, gt + j * a[i].v);
        if(j)
            res.pop_back();
    }
}

void init() {
    cin >> n >> m;
    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].v;
        s[i] = s[i-1] + a[i].v;
    }
    solve(1, 0, 0);
    cout << gmax << '\n';
    for(auto i : ans)
        cout << i << " " ;
}

#define task "KNAPSACK1"
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
        // solve();
    }
    //cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}