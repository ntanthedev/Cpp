#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf pop_front
#define fi first
#define se second
const int N = 1e6 + 9;
using namespace std;
template<typename T>
inline void read(T& x) {
    bool b = 0;
    char c;
    while(!isdigit(c = getchar()) && c != '-')
        ;
    if(c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while(isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if(b) {
        x = -x;
    }
}
ll t;
pair<ll, ll> a[10];
//---solution---
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(ll i = 1; i <= t; i++) {
        ll l, r;
        for(ll j = 1; j <= 3; j++)
            cin >> a[j].fi >> a[j].se;
        sort(a + 1, a + 4);
        a[4].fi = max(a[1].fi, a[2].fi);
        a[4].se = min(a[1].se, a[2].se);
        a[5].fi = max(a[3].fi, a[2].fi);
        a[5].se = min(a[3].se, a[2].se);
        a[6].fi = max(a[1].fi, a[3].fi);
        a[6].se = min(a[1].se, a[3].se);
        l = max({a[4].fi, a[5].fi, a[6].fi});
        r = min({a[4].se, a[5].se, a[6].se});
        if(l > r)
            cout << 0 << '\n';
        else
            cout << r - l + 1 << '\n';
    }
}