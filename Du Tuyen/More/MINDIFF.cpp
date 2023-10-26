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

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll res = 0, ans = LLONG_MIN, n, k, a[N], s[N];

void solve(){
    sort(a+1, a+1+n);
    for(int i = 1; i <= k; i++) {
        res += abs((a[i]*(k-i)) - (s[k]-s[i]));    
    }
    ll d = k;
    for(int i = 2; i <= n-k+1; i++){
        res -= abs((a[i-1]*(k-1)) - (s[d]-s[i-1]));
        res += abs(a[d+1]*(k-1)-(s[d]-s[i-1]));
        d++;
        ans = min(res,ans);
    }
    cout << ans;
}

void init(){
    cin >> n >> k;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
}
#define task "MINDIFF"
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