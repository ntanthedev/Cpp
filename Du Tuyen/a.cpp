//Written by: ntannn_
//created in 11:18:11 - Mon 08/07/2024
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

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;

ll trie[N * 32][2], cnt = 0;
vector<bool> End(32 * N, false);
char c;
ll k; 

void add(ll x) {
    ll cur = 0;
    for(int i = __lg(x); i >= 0; i--) {
        int u = (x >> 1 & 1);
        // End[cnt] = 0;
        if(!trie[cur][u])
            trie[cur][u] = ++cnt;
        cur = trie[cur][u];
        // End[cur] = true;
    }
}

void solve() {
    if(c == '+') {

    }
}

void init() {
    cin >> c >> k;
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
    cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}