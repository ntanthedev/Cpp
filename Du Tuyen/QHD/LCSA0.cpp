#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e3+10;
const ll MOD = 1e9+7;

ll m, n, a[N], b[N], dp[N][N];

void solve() {
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max({dp[i-1][j], dp[i][j-1]});            
        }
    }
    cout << dp[n][m];
}

void init() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
}

#define task "LCSA0"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    //cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}