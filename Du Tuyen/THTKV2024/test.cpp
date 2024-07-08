
#include <bits/stdc++.h>
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;
typedef int ll;
ll next(ll x, ll k, ll z, ll zz, bool o, ll zzz) {
    // cout<<x<<" ";
    if(!k)
        return x;
    if(x > 1e15)
        return -1;
    if(k > z) {
        k -= (z + 1);
        if(o)
            z += zzz;
        else {
            z = ((ll) (__lg(x)) - (ll) (__lg(zz))) * zzz;
            // cout<<z;
            o = true;
        }
        x = (1 << (ll) (__lg(x) + 1));
        x += zz;
    } else {
        ll h = (ll) (__lg(x));
        ll d = 2;
        while(k >= (zzz)) {
            k -= zzz;
            x = (1 << (ll) (__lg(x))) + zz * d;
            d *= 2;
        }
        while(k > 0) {
            bool o = false;
            ll save = 0;
            for(ll i = 0; i <= h; i++) {
                if(k <= 0)
                    break;
                if((1 << i) & x) {
                    o = true;
                    save = (1 << i);
                    continue;
                }
                if(!o)
                    continue;
                x += (1 << i);
                x -= save;
                break;
            }
            k--;
            if(k <= 0)
                break;
        }
        if(x > 1e15)
            return -1;
        return x;
    }
    next(x, k, z, zz, o, zzz);
}
void solve() {
    ll x, k;
    cin >> x >> k;
    ll z = 0, zz = (ll) (__lg(x));
    bool oo = false;
    ll xxx = 0;
    for(ll i = 0; i < zz; i++) {
        if((1 << i) & x) {
            oo = true;
            xxx++;
            continue;
        }
        if(oo)
            z += xxx;
    }
    ll zzz = __builtin_popcount(x);
    zzz--;
    ll zzzz = 0;
    for(ll i = 0; i < zzz; i++) {
        zzzz += (1 << (i));
    }
    bool o = false;
    ll xxxx = __builtin_popcount(x);
    xxxx--;
    ll xx = next(x, k, z, zzzz, o, xxxx);
    cout << xx;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#define task "a"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        //  freopen(task ".out", "w", stdout);
    }
    ll tests;
    cin >> tests;
    while(tests--) {
        solve();
        cout << '\n';
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}