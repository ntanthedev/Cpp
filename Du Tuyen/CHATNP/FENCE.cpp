#include<bits/stdc++.h>


const long long N = 1e5+9;
using namespace std;

typedef long long ll;

ll n, k;
ll a[N];

bool check(ll x) {
    ll kk = k;
    for(int i = 1; i < n; ++i) {
        ll t = (a[i + 1] - a[i])/x;
        kk -= t;
        if(kk < 0) return false;
    }
    return (kk >= 0);
}

void solve() {
    sort(a+1, a+1+n);
    ll l = 1, r = 1e9, ans = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }
    cout << check(3);/////
    // cout << ans;
}

#define task "FENCE"
signed main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    solve();
}
