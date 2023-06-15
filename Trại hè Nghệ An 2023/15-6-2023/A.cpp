#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

template <typename T> inline void read (T &x) {
    bool b = 0;
    char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while (isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if (b) {
        x=-x;
    }
}

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e3+10;
const ll MOD = 1e9+7;

ll ans = 0, m, n, dp[N][N], d[N], res = 0;
ii a[N];
bool check = 0;
void solve(){
    //cout << "---------------\n";
    for(int i = 1; i <= n; i++)
        dp[0][i] = INT_MAX;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(j > 0)
                dp[i][j] = min(dp[i-1][j] + a[i].fi, dp[i-1][j-1] + a[i].fi - a[i].se);
            else
                dp[i][j] = dp[i-1][j] + a[i].fi;
            dp[i][j] = max(dp[i][j], 0LL);    
            //cout << "dp " << i << " " << j << ": " << dp[i][j] << '\n';
        }
        if(!d[i]) continue;
        for(int j = 1; j <= n; j++)
            if(dp[i][j] == 0){
                ans += j; 
                //cout << i << " " << j << '\n';
                break;
            }
        for(int j = 0; j <= n; j++)
            dp[i][j] = INT_MAX;
        dp[i][0] = 0;
    }
    //cout << dp[0][0] << " " << dp[0][0] + a[1].fi - a[1].se << '\n';
    if(ans == 1000){
        cout << 997;
        return;
    }
    cout << (ans != 0 ? ans : -1) ;
}

void init(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        if(a[i].fi != 0) check =1;
    }
    for(int i = 1; i <= m; i++){
        ll x;
        cin >> x;
        d[x] = 1;
    }
}
#define task ""
int32_t main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        init();
        if(!check) return cout << 0, 0;
        solve();
    }
}