//Written by: ntannn_
//created in 19:51:51 - Fri 05/04/2024
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

string s;
ll n, ans = 0;

void solve() {
    n = s.size();
    s = ' ' + s;
    vector<ll> vt;
    ll gmax = 0, d = 1;
    for(ll i = 1; i <= n; i++) {
        if(s[i] == '(')
            vt.pb(i);
        else {
            if(!vt.empty()) {
                if(i - vt.back() + 1 > gmax)
                    gmax = i - vt.back() + 1, d = 1;
                else 
                    if(i - vt.back() + 1 == gmax)
                        d++;
                vt.pop_back();
            }
        }
    }
    cout << gmax << " " << d;
}

void init() {
    cin >> s;
}

#define task "5C"
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