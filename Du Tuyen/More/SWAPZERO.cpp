//Written by: ntannn_
//created in 20:34:20 - Wed 13/03/2024
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

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

int n;
vi a;
map<int, int> m;
vi ans;

void solve() {
    while(m[0] != 0) {
        int t = m[0];
        ans.pb(t);
        m[0] = m[t];       
        m.erase(t);
    }
    // cout << m.size() << '\n';
    while(m[0] == 0 && m.size() > 1) {
        auto it = (*++m.begin()).fi;
        swap(m[0], m[it]);
        ans.pb(it);
        while(m[0] != 0) {
            int t = m[0];
            ans.pb(t);
            m[0] = m[t];        
            m.erase(t);
        }
        // m.erase(0);
    }

    cout << ans.size() << '\n';
    for(auto i : ans)
        cout << i << " ";
}

void init() {
    cin >> n;
    for(int i = 0, x; i <= n; i++) {
        cin >> x;
        if(x != i)
            m[x] = i;
        if(x != i)
            a.pb(x);
    }
}

#define task "SWAPZERO"
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