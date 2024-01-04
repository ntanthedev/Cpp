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

const int N = 5e3+10;
const ll MOD = 1e9+7;

ll n, a[N];
vector<vector<ll>> dp;

void solve() {
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(a[j] < a[i] && dp[j].size() >= dp[i].size()) {
                dp[i] = dp[j];
                dp[i].eb(i);
            }
        }
    }
    vll temp;
    for(auto i : dp)
        if(i.size() > temp.size()) {
            temp = i;
        }
    cout << temp.size() << '\n';
    for(auto i : temp)
        cout << i << " " ;
    // cout << *max_element(all(dp));
}

void init() {
    cin >> n;
    dp.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i].eb(i);
    }
    
}

#define task "LIQ"
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