#include<bits/stdc++.h>


const long long N = 1e6+9;
using namespace std;

typedef long long ll;

ll n, m;
vector<ll> a;

bool check(ll x) {
    ll res = 0, cnt = 1;
    for(auto i : a) {
        if(i > x) return false;
        if(res + i > x)
            cnt++, res = 0;
        res += i;
    }
    return (cnt <= m);
}

void solve() {
    ll l = 1, r = LLONG_MAX, ans;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid)) {
            r = mid-1;
            ans = mid;
        }
        else 
            l = mid+1;
    }
    cout << ans;
}

#define task "DAYSO"
signed main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    a.resize(n);
    for(auto &i : a) 
        cin >> i;
    solve();
}