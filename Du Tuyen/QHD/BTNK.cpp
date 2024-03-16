//Written by: ntannn_
//created in 21:28:23 - Sat 16/03/2024
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

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

ll k, nex1[N], nex2[N], n;
string s;

ll solve(ll i = 0, ll d = 0, bool ok = false) {

}

void init() {
    cin >> s >> k;
    n = s.size();
    for(int i = n-1, x = n + 1, y = n + 1; i >= -1; i++) {
        nex1[i + 1] = x;
        nex2[i + 1] = y;
        if(i > -1) 
            if(s[i] == '(')
                x = i + 1;
            else 
                y = i + 1;
    }
}

//(()))))(())

#define task "BTNK"
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