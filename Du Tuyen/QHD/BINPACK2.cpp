//Written by: ntannn_
//created in 20:21:52 - Thu 14/03/2024
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

int n, k, a[102], W = 0;
string ans;
bool ok;

void sub1(int i = 1, ll res1 = 0, ll res2 = 0, int kk = 0) {
    if(ok)
        return;
    if(i > n) {
        cout << ans << '\n';
        ok = 1;
        return;
    }
    for(int j = 0; j <= 2; j++) {
        if((!j && kk == k) || res1 + a[i]*(j == 1) > W/2 || res2 + a[i]*(j == 2) > W/2)
            continue;
        ans.pb(char(j + '0'));
        sub1(i+1, res1 + a[i]*(j == 1), res2 + a[i]*(j == 2), kk + (j == 0));
        ans.pop_back();
    } 
}

void sub2_1(int i = 1, ll res1 = 0, ll res2 = 0, int kk = 0) {
       
}

void solve() {
    ok = 0;
    if(n <= 20)
        sub1();
}

void init() {
    W = 0;
    cin >> n >> k;   
    for(int i = 1; i <= n; i++) 
        cin >> a[i], W += a[i];
}

#define task "BINPACK2"
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
        ans.clear();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}