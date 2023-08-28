#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

int n, f[N][N], ans = 0;
string s, res;

void solve(int i, int d, int bac) {
    if(i > n) {
        if(d == 0) {
            if(bac > ans) {
                ans = bac;
                f[i][d] = bac;
            
            }
        }
        return;
    }

    if(f[i][d] != -1) {

        return;
    }

    f[i][d] = 0;
    if(s[i] != ')' && d < n - i) {
        solve(i + 1, d + 1, max(bac, d + 1));
        f[i][d] = max(f[i][d], f[i + 1][d + 1]);
    }
    if(s[i] != '(' && d - 1 >= 0) {
        solve(i + 1, d - 1, bac);
        f[i][d] = max(f[i][d], f[i + 1][d - 1]);
    }
}

void init() {
    cin >> s;
    n = s.size();
    s = ' ' + s;

    memset(f, -1, sizeof(f));

    solve(1, 0, 0);

    cout << ans;
}

#define task "BTN2"
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    // cin >> test_case;
    while(test_case--) {
        init();
        // solve();
    }
}