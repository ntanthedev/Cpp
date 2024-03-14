//Written by: ntannn_
//created in 19:42:43 - Thu 14/03/2024
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

struct pt {
    ll l, h, vt;
};

pt c[N];
ll n, a, b;
vi ans;

void solve() {
    sort(c + 1, c + 1 + n, [&](pt x, pt y) {
        return x.l < y.l || (x.l == y.l && x.h < y.h);
    });
    while(a < b) {
        int k = -1;
        for(int i = 1; i <= n; i++) {
            if(c[i].l <= a) {
                if(k == -1 || c[i].h > c[k].h)
                    k = i;
            }
            else 
                break;
        }

        if(k == -1 || c[k].h < a) 
            return cout << -1, void();
        
        ans.pb(c[k].vt);
        a = c[k].h;
    }
    if(ans.empty())
        cout << -1;
    else {
        cout << ans.size() << '\n';
        for(auto i : ans)
            cout << i << '\n';
    }
}

void init() {
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        cin >> c[i].l >> c[i].h;
        c[i].vt = i;
    }
}

#define task "COVER"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}