#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
vector<ll> ntt(1000021), dp(1000021);
void sieve() {
    for(ll i = 1; i <= 1000000; i++)
        ntt[i] = i;
    for(ll i = 2; i <= 1000000; i++) {
        if(ntt[i] == i) {
            for(ll j = i * i; j <= 1000000; j += i)
                ntt[j] = i;
        }
    }
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    a[0] = 1e9 + 7;
    ll ans = 0, save = 0, maxx = 0;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
        ll x = a[i];
        if(!x) {
            ans = max(ans, maxx + i - save);
        } else
            maxx = 0;
        while(x > 1) {
            ll h = ntt[x];
            while(x % h == 0) {
                x /= h;
            }
            if(a[save] % h == 0) {
                dp[h] += i - save;
                ans = max(ans, dp[h]);
                maxx = max(maxx, dp[h]);
            } else {
                dp[h] = i - save;
                ans = max(ans, dp[h]);
                maxx = max(maxx, dp[h]);
            }
        }
        if(a[i])
            save = i;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    sieve();
    ll tests;
    cin >> tests;
    while(tests--) {
        solve();
        cout << '\n';
    }
}