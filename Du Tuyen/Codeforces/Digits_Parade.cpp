//Written by: ntannn_
//created in 23:38:07 - Mon 25/03/2024
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

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

ll f[N][14], n;
string s;

ll solve(int i, int k) {
    if(i > n)
        return (k == 5);
    if(f[i][k] != -1)
        return f[i][k];
    f[i][k] = 0; 
    if(s[i] == '?') {
        for(int j = 0; j <= 9; j++) 
            f[i][k] += solve(i + 1, (k * 10 + j) % 13) % MOD;
    }
    else {
        f[i][k] += solve(i + 1, (k * 10 + (s[i] - '0')) % 13) % MOD;
    }
    return f[i][k] % MOD;
}
    
// 100 + 9 => 1009

// (x * 10 + j) % mod

void init() {
    cin >> s;
    n = s.size();
    s = ' ' + s;
}

#define task "Digits Parade"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    
    init();
    memset(f, -1, sizeof(f));
    
    cout << solve(1, 0);    
}