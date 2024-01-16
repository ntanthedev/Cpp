#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define inff 1e8
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

pair<int, int> a[5];
int xx = -inff, yy = -inff, zz = -inff, tt = -inff;
void solve() {
    for(int i = 1; i <= 4; i++) {
        if(xx == -inff)
            xx = a[i].fi;
        else if(xx != a[i].fi)
            zz = a[i].fi;
        if(yy == -inff)
            yy = a[i].se;
        else if(yy != a[i].se)
            tt = a[i].se;
    }
    cout << abs((xx - zz) * (yy - tt));
}

void init() {
    xx = -inff, yy = -inff, zz = -inff, tt = -inff;
    for(int i = 1; i <= 4; i++) 
        cin >> a[i].fi >> a[i].se;
}

#define task "aa"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;

    cin >> test_case;
    while(test_case--) {
        init();
        solve();
        cout << '\n';
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}