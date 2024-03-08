//Written by: ntannn_
//created in 14:09:31 - Fri 08/03/2024
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf pop_front
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

const int N = 3e6 + 10;
const ll MOD = 1e9 + 7;

ll n, k, a[N];
deque<ll> dmax, dmin;

void solve() {
    int l = 1, r = 1, gmax = 1, gmin = 1;
    dmax.pb(a[1]);
    dmin.pb(a[1]);
    while(r <= n) {

        ++r;
        while(a[dmax.back()] <= a[r])
            dmax.pop_back();
        dmax.pb(r);
        while(a[dmin.back()] >= a[r])
            dmin.pop_back();
        dmin.pb(r);        
    }
}

void init() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
}

#define task "FGARDEN"
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