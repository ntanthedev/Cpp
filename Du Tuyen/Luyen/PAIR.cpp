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

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll m, n, a[N], b[N], k;

bool check(int x) {
    ll res = 0;
    ll i = 1, j = 1;
    while(i <= m && j <= n) {
        if(abs(a[i] - b[j]) <= x)
            res++, i++, j++;
        else if(a[i] < b[j])
            i++;
        else 
            j++;
    }
    if(res >= k)
        return true;
    return false;
}


void solve() {
    sort(a+1, a+1+m);
    sort(b+1, b+1+n);
    int l = 0, r = 1e9, ans = 1e9;
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid)) {
            r = mid-1;
            ans = min(ans, mid);
        }
        else {
            l = mid+1;
        }
    } 
    cout << ans;
}

void init() {
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
}

#define task "PAIR"
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
}