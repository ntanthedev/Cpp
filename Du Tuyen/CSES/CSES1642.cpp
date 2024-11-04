//Written by: ntannn_
//created in 18:54:47 - Tue 25/06/2024
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

const int N = 5e3 + 10;
const ll MOD = 1e9 + 7;

ll n, a[N], x, ans = 0;
map<ll, vector<ii>> M;

void solve() {

    for(int i = 1; i <= n; i++) 
        for(int j = i + 1; j <= n; j++) { 
            auto it = M.find(x - a[i] - a[j]);
            if(it != M.end()) {
                for(auto k : it->se) {
                    if(k.fi != i && k.fi != j && k.se != i && k.se != j) 
                        return cout << k.fi << " " << k.se << " " << i << " "  << j, void();
                }
            }
            M[a[i] + a[j]].pb({i, j});
        }
    
    cout << "IMPOSSIBLE";
}

void init() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
}

#define task "a"
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