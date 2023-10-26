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

int n, f[667][334][334], ans = 0;
string s, res, x;

int solve(int i, int d, int bac) {
    if(i > n - 1) {
        if(d == 0) {
            if(bac > ans) {
                ans = bac;
                res = x;
            }
            return bac;
        } else
            return 0;
    }

    if(f[i][d][bac] != -1) {
        return f[i][d][bac];
    }

    f[i][d][bac] = 0;
    if(s[i] != '(' && d > 0) {
        x[i] = ')';
        f[i][d][bac] = max(f[i][d][bac], solve(i + 1, d - 1, bac));
    }
    if(s[i] != ')' && d < n / 2) {
        x[i] = '(';
        f[i][d][bac] = max(f[i][d][bac], solve(i + 1, d + 1, max(d + 1, bac)));
    }
    return f[i][d][bac];
}

void init() {
    cin >> s;

    x = s;

    n = s.size();

    memset(f, -1, sizeof(f));

    res.resize(n);

    solve(0, 0, 0);

    cout << res;
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