//Written by: ntannn_
//created in 17:18:14 - Tue 12/03/2024
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

ll n, a[N], s[N];

ll cal(int l, int r) {
    ll res = s[r] - s[l-1];
    if(res & 1)
        return 0;
    int t = lower_bound(s + 1, s + 1 + n, s[l-1] + res/2) - s;
    if((s[t] - s[l-1]) * 2 == res)
        return max(cal(l, t), cal(t+1, r)) + 1;
    else 
        return 0;
} 

void solve() {
    cout << cal(1, n);
}

void init() {
    cin >> n; s[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i-1] + a[i];
}

#define task "SEQ"
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