//Written by: ntannn_
//created in 06:13:48 - Sun 17/03/2024
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
const ll MOD = 111539786;

int n, k;
int f[N][N];

ll solve(int i = 0, int d = 0) {
    if(i >= n) {
        if(d < k)
            return 1;
        return 0;
    }  

    if(f[i][d] != -1)
        return f[i][d];
    
    f[i][d] = 0;
    if(d < k - 1)
        f[i][d] += solve(i + 1, d + 1) % MOD;
    f[i][d] += solve(i + 1, 0) % MOD;
    return f[i][d] % MOD; 
}


#define task "DNPK"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(cin >> n >> k) {
        // init();
        memset(f, 255, sizeof(f));
        cout << solve() << '\n';
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}