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

const int N = 1e5+10;
const ll MOD = 1e9+7;
int n, a[N], x[N];
priority_queue<ii, vii, greater<ii>>q;
int dp[N];
void solve(){
    q.push(mp(0, 0));
    for(int i = 1, j = 0; i <= n; i++){
        while(!q.empty() && q.top().fi <= x[i]) {
            j = max(j, q.top().se);
            q.pop();
            //cout << i << " "; dbg(dp[i]);
        }
        dp[i] = min(dp[i], x[i] - x[j]);
        q.push(mp(dp[i] + x[i], i));
    }
    int ans = INT_MAX;
    for(int i = 1 ; i <= n; i++) {
        ans = min(ans, max(dp[i], x[n] - x[i]));
    }
    cout << ans;
}

void init(){
    read(n);
    for(int i = 1; i <= n; i++){
        read(a[i]);
        x[i] = x[i-1] + a[i];
        dp[i] = INT_MAX;
    }
}
#define task "code"
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