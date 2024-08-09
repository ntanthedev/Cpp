#include<bits/stdc++.h> 

using namespace std;

typedef long long ll;

ll sum(ll x) {
    ll res = 0;
    while(x) {
        res += (x % 10) * (x % 10);
        x /= 10;
    }
    return res;
}

bool check(ll x) {
    ll t = sum(x);
    for(int i = 1; i <= 15; i++) {
        t = sum(t);
        if(t == 1) 
            return true;
    }
    return false;
}

void solve() {
    ll a, b, ans = 0;
    cin >> a >> b;
    for(ll i = a; i <= b; i++) {
        if(check(i))
            ans++;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--) {
        solve();
    }
}