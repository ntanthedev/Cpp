#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
const int N = 1e6 + 9;
const ll MOD = 1e9 + 3;
const ll base = 31;

ll ans = 0, n, POW[N], Hasha[N], Hashb[N];
string a, b;

ll get_hasha(ll i, ll j) {
    return (Hasha[j] - Hasha[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

ll get_hashb(ll i, ll j) {
    return (Hashb[j] - Hashb[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

bool check(ll x) {
    for(int i = 1; i <= n - x + 1; i++) {
        ll l = get_hasha(i, i + x - 1);
        ll r = get_hashb(n - (i + x - 1) + 1, n - i + 1);
        if(l == r)
            return true;
    }
    return false;
}

void solve() {
    // n = s.size();
    a = ' ' + a;
    b = ' ' + b;
    POW[0] = 1;
    Hasha[0] = 0;
    Hashb[0] = 0;
    for(int i = 1; i <= n; i++) {
        POW[i] = (POW[i - 1] * base) % MOD;
    }
    for(int i = 1; i <= n; i++) {
        Hasha[i] = (Hasha[i - 1] * base + a[i] - 'a' + 1) % MOD;
    }
    for(int i = 1; i <= n; i++) {
        Hashb[i] = (Hashb[i - 1] * base + b[i] - 'a' + 1) % MOD;
    }

    ll l = 1, r = n - (n % 2 == 0), mid;
    while(l < r) {  // chat le
        mid = (l + r) / 2;
        if(mid % 2 == 0)
            mid++;
        if(check(mid)) {
            l = mid;
            ans = mid;
        } else {
            r = mid - 2;
        }
    }

    l = 0, r = n - (n % 2);
    while(l < r) {  // chat chan
        mid = (l + r) / 2;
        if(mid % 2 != 0)
            mid++;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 2;
        }
    }
    ans = max(l, ans);
    for(int i = 1; i <= n - ans + 1; i++) {
        ll l = get_hasha(i, i + ans - 1);
        ll r = get_hashb(n - (i + ans - 1) + 1, n - i + 1);
        if(l == r) {
            for(int j = i; j <= i + ans - 1; j++)
                cout << a[j];
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    b = a;
    reverse(all(b));

    solve();
}
