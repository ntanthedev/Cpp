//Written by: ntannn_
//created in 18:57:37 - Sun 11/05/2025
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

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

int n, k;
bool p[N + 10];
vi a, b(N + 10, 0);

void sang() {
    memset(p, true, sizeof(p));

    p[0] = p[1] = false;

    for(int i = 2; i <= sqrt(N); i++) 
        if(p[i]) 
            for(int j = i * i; j <= N; j += i) 
                p[j] = 0;
}

void solve() {
    cin >> n >> k;

    sang();

    for(int i = 1; i <= N; i++) 
        if(p[i]) 
            a.pb(i);

    for(int i = 1; i < a.size(); i++) {
        int t = a[i] + a[i - 1];
        if(t <= N && p[t + 1]) {
            b[t + 1] = 1;
            // if(t < n)
            // cout << a[i - 1] << " " << a[i] << " " << t + 1 << '\n';
        } 
    }
    
    for(int i = 1; i <= N; i++) 
        b[i] += b[i - 1];

    if(b[n] >= k) 
        cout << "YES";
    else 
        cout << "NO";
}

#define task "code"
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