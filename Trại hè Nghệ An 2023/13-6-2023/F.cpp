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

const int N = 1e6+10;
const ll MOD = 1e9+7;


int m, n;
ll a[N];
vector<ll>  f(N), dp(N), cnt(N);
inline ll com3(ll x){
    return (((x * (x-1)) * (x-2)) / 6);
}

void solve(){
    // dp[i] la so cach chon 3 thang sao cho gcd == i
    for(int i = n; i >= 1; i--) {
        for(int j = i; j <= n; j += i)
            dp[i] += cnt[j];
    }
    for(int i = n; i >= 1; i--) {
        dp[i] = com3(dp[i]);
        for(int j = i + i; j <= n; j += i)
            dp[i] -= dp[j];
    }
    cout << (dp[1] % MOD) << endl;
}

void init(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] % m != 0) continue;
        a[i] /= m;
        cnt[a[i]]++;
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
        solve();
    }
}