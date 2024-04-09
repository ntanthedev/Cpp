//Written by: ntannn_
//created in 14:24:38 - Tue 09/04/2024
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

const int N = 1e5 + 2;
const ll MOD = 1e9 + 7;
const int BLOCK_SIZE = 320;

ll n, cnt[N / BLOCK_SIZE + 2][N];
vll s(N + 3, 0);

void solve() {
    
}

void init() {
    cin >> n;
    for(int i = 1; i <= sqrt(N); i++) {
        for(int j = 2; j * i <= N; j++) 
            s[i * j] += i;
    }
    for(int i = 1; i <= n; i++) {
        ++cnt[i / BLOCK_SIZE][s[i]];
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
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}