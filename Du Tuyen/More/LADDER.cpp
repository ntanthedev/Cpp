//template for some simple code by ntannn_
//created in 07:57:07 - Thu 25/01/2024
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

ll n, Q, a[N], L[N], R[N];

void solve() {
    while(Q--) {
        int l, r;
        cin >> l >> r;
        if(R[l] + L[r] >= (r - l + 1))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    // cout << "\x1b[31mstart debug: \n";

    // cout << "end of debug\e[39m \n";

}

void init() {
    cin >> n >> Q;
    // memset(L, 1, sizeof(L));
    // memset(R, 1, sizeof(R));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        L[i] = 1;
        R[i] = 1;
    }
    for(int i = 2; i <= n; i++)
        if(a[i] <= a[i-1])
            L[i] = L[i-1] + 1;
    for(int i = n-1; i >= 1; i--) 
        if(a[i] <= a[i+1])
            R[i] = R[i-1] + 1;
    // cerr << "\x1b[31mstart debug: \n";
    // for(int i = 1; i <= n; i++) cerr << L[i] << " "; cerr << '\n';
    // for(int i = 1; i <= n; i++) cerr << R[i] << " "; cerr << '\n';
    // cerr << "end of debug\e[39m \n";
}

#define task "LADDER"
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