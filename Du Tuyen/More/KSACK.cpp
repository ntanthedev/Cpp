#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define w first
#define v second
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

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, W;
pll a[1003];
ll L[1003][1003];
ii trace[1003][1003];

void solve() {
    L[0][0] = 0;
    trace[0][0] = mp(-1, -1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            if(j >= a[i].w && L[i-1][j-a[i].w] + a[i].v > L[i][j]) {
                trace[i][j] = mp(i-1, a[i].w);
            }
            if(j >= a[i].w) 
                L[i][j] = max(L[i-1][j-a[i].w] + a[i].v, L[i-1][j]);
            else    
                L[i][j] = L[i-1][j];
        }
    }
    cout << L[n][W];
}

void init() {
    cin >> n >> W;
    for(int i = 1; i <= n; i++)
        cin >> a[i].w >> a[i].v;
}

#define task "KSACK"
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