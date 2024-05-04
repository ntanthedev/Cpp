//Written by: ntannn_
//created in 14:13:38 - Sat 04/05/2024
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

ll n, s[N], res = 0;
string ans;
vector<string> as;

void solve(int i = 1, ll a = 0, ll b = 0, ll c = 0) {
    if(i > n) {
        if(a + b + c == res)
            as.eb(ans);
    }
    if(a + s[i] <= res / 3) {
        ans.pb('A');
        solve(i + 1, a + s[i], b, c);
        ans.pop_back();
    }
    if(b + s[i] <= res / 3) {
        ans.pb('B');
        solve(i + 1, a, b + s[i], c);
        ans.pop_back();
    }
    if(c + s[i] <= res / 3) {
        ans.pb('C');
        solve(i + 1, a, b, c + s[i]);
        ans.pop_back();
    }     
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> s[i], res += s[i];
}

#define task "CHIARUONG"
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
        if(res % 3 != 0)
            return cout << -1, signed();
        solve();
        cout << as.size() << '\n';
        for(auto i : as)
            cout << i << '\n';
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}