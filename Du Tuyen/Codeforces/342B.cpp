//Written by: ntannn_
//created in 08:44:20 - Wed 20/03/2024
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
const int base = 311;
const ll MOD = 1e9 + 7;

ll P[N], A[N], B, ans = 0;
string a, b;

ll getA (int i, int j) {
    return (A[j] - A[i-1] * P[j - i + 1] + MOD * MOD) % MOD;
}

void solve() {
    for(int i = 1; i <= a.size() + 1; i++) 
        P[i] = (P[i-1] * base) % MOD;
    for(int i = 1; i < a.size(); i++) 
        A[i] = (A[i-1] * base + a[i] - 'a' + 1) % MOD;
    for(int i = 1; i < b.size(); i++)
        B = (B * base + b[i] - 'a' + 1) % MOD;
    
    for(int i = b.size() - 1; i < a.size(); i++) {
        if(getA(i - b.size() + 2, i) == B) {
            ans++;
            i += b.size() - 2;
        }
        // cout << i - b.size() + 2 << " " << i << '\n';
    }
    // cout << getA(3, 6) << " " << B << " " << b.size() << '\n';
    cout << ans;
}

void init() {
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    P[0] = 1;
    A[0] = 0;
}

#define task "342B"
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