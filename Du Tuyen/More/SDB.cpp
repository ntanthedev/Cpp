//Written by: ntannn_
//created in 20:05:39 - Wed 13/03/2024
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


bool b[1000068];
vector<int> f;

void sang(int NN) {
    memset(b, true, sizeof(b));
    b[0] = 0;
    b[1] = 0;
    for(int i = 2; i <= sqrt(NN); i++) 
        if(b[i])
            for(int j = i*i; j <= NN; j += i)
                b[j] = 0;
}

int x, y;

void solve() {
    int l = lower_bound(all(f), x) - f.begin();
    int r = upper_bound(all(f), y) - f.begin() - 1;
    cout << r - l + 1 << '\n';
}

void init() {
    cin >> x >> y;
}

#define task "SDB"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    f.pb(0);
    sang(N);
    for(int i = 2; i*i*9 <= N; i++)
        if(b[i] && i != 3 || i == 27)
            f.pb(i*i*9);
    int test_case = 1;
    
    
    
    
    cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}