#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
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

const int N = 5e3+10;
const ll MOD = 1e9+7;
const int inf = 1e9;

int dp[N][N], f[N][N], n;

void solve(){
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            f[i][j] = inf;
    for(int i = 0; i <= n; i++)
        f[0][i] = 0;
    dp[0][0] = 0; 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = f[i-j][j-1] + (j-1)*j/2;
        }
        for(int j = 1; j <= n; j++)
            f[i][j] = min(f[i][j-1], dp[i][j]);
    }
    
    cout << f[n][n];
}   

void init(){
    cin >> n;
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
        solve();
    }
}