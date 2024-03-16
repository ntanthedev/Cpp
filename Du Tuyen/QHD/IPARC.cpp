//Written by: ntannn_
//created in 19:54:25 - Sat 16/03/2024
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

ll n, cnt = 0;
vi ans;

void solve(int i = 1, int res = 0, int last = 0) {
    if(res == n) {
        ++cnt;
        for(auto i : ans)
            cout << i << " ";
        return cout << '\n', void();
    }
    for(int j = last + 1; j <= n; j++) {
        if(res + j > n)
            break;
        ans.pb(j);
        solve(i + 1, res + j, j);
        ans.pop_back();
    }
}

void init() {
    cin >> n;
}

#define task "IPARC"
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
        cout << cnt;
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}