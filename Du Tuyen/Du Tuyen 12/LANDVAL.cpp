// Written by: ntannn_
// created in 09:44:17 - Thu 01/08/2024
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

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

int n, m, a[N][N], k, t[N][N];

void solve() {
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++) 
        for(int j = 1; j <= n; j++) 
            cin >> a[i][j];
    
    for(int i = 1; i <= m; i++) {
        deque<int> q;
        for(int j = 1; j <= n; j++) {
            while(!q.empty() && a[i][q.back()] < a[i][j])
                q.pop_back();
            while(q.front() < j - k + 1)
                q.pop_front();
            t[i][j] = a[i][q.front()];
        }
    }
     
    for(int i = 1; i <= n; i++) {
        deque<int> q;
        for(int j = 1; j <= m; j++) {
            while(!q.empty() && a[q.back()][i] < a[j][i])
                q.pop_back();
            while(q.front() < j - k + 1)
                q.pop_front();
            t[i][j] = a[i][q.front()];
        }
    }
}

#define task "LANDVAL"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    // cin >> test_case;
    while(test_case--) {
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}

