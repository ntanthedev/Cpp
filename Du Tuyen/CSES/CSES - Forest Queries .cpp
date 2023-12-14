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

ll n, Q;
int a[N][N], s[N][N];
char c;

void solve() {
    ii x, y;
    while(Q--) {
        cin >> x.fi >> x.se >> y.fi >> y.se;
        cout << a[y.fi][y.se] - a[x.fi-1][y.se] - a[y.fi][x.se-1] + a[x.fi-1][x.se-1] << '\n';
    }
}

void init() {
    cin >> n >> Q; 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c;
            a[i][j] = a[i][j-1] + a[i-1][j] - a[i-1][j-1] + (c == '*');
        }
    }
}

#define task "CSES - Forest Queries "
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