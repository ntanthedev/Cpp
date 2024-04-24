//Written by: ntannn_
//created in 14:58:46 - Wed 24/04/2024
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

int n, k, a[N], ans = 0;
map<int, int> M;

void solve() {
    for(int i = 1; i < k; i++) 
        M[a[i]]++;
    for(int i = k; i <= n; i++) {
        M[a[i]]++;
        vi tmp;
        for(auto i : M)
            tmp.pb(i.fi);
        int t1 = tmp[M.size() / 2], t2 = tmp[M.size() / 2 - 1];
        // cout << i - k + 1 << " " << i << '\n';
        // cout << "tmp: ";
        // for(auto i: tmp) cout << i << " "; cout << '\n';
        
        if(M.size() & 1) {
            int c1 = 0, c2 = 0;
            for(auto i : tmp)
                c1 += abs(i - t1);
            for(auto i : tmp) 
                c2 += abs(i - t2);
            ans = max({ans, c1, c2});
            // cout << c1 << " " << c2 << " " << ans << '\n';
        }
        else {
            int c1 = 0;
            for(auto i : tmp)
                c1 += abs(i - t1);
            ans  = max({ans, c1});
            // cout << c1 << " " << ans << '\n';
        }
        // cout << '\n';

        M[a[i-k+1]]--;
        if(M[a[i-k+1]] == 0)
            M.erase(a[i-k+1]);
    }    
    cout << ans;
}

void init() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

#define task "CANDY"
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