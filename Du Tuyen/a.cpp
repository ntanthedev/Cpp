//Written by: ntannn_
//created in 21:56:13 - Fri 02/08/2024
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

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

int n;
tuple <int, int, int> s[N];
map<int, int> M;

void update(int id, int l, int r) {

}

void solve() {
    cin >> n;

    for(int i = 1, a, b, h; i <= n; i++) {
        cin >> a >> b >> h;
        s[i] = {a, b, h};
        M[a]++;
        M[b]++;
        M[h]++;
    }

    int m = 0;

    for(auto &i : M) {
        i.se = ++m;
    }

    for(int i = 1; i <= n; i++) {
        auto [a, b, c] = s[i];
        a = M[a];
        b = M[b];
        c = M[c];
    }

    
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
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}