//Written by: ntannn_
//created in 14:05:41 - Sat 04/05/2024
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

vii a(4);

void solve() {
    sort(all(a));
    if(a[0].fi == a[1].fi && a[2].fi == a[3].fi && a[0].se == a[2].se && a[1].se == a[3].se)
        cout << abs(a[0].se - a[1].se) * abs(a[0].se - a[1].se);
    else 
        cout << -1; 
}

void init() {
    for(int i = 0; i < 4; i++) 
        cin >> a[i].fi >> a[i].se;
}

#define task "HINHVUONG"
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