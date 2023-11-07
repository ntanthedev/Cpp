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

ll n, a[N], f[N], m = 0;
vi s, ans;

void solve() {
    s.eb(a[1]);
    f[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(a[i] > s.back()) {
            s.eb(a[i]);
            f[i] = s.size();
        }
        else {
            ll t = lower_bound(all(s), a[i]) - s.begin();
            s[t] = a[i];
            f[i] = t + 1;
        }
    }
    m = s.size();
    cout << m << '\n';
    for(int i = n; i >= 1; --i) {
        if(f[i] == m) {
            ans.eb(i);
            m--;
        }
    }
    reverse(all(ans));
    for(auto i : ans)
        cout << i << " " ;
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

#define task "LIS"
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
    cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}