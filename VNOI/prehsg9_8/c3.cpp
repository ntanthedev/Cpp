#include<bits/stdc++.h>

#define int long long

const int N = 2e6 + 5;
typedef long long ll;

using namespace std;

ll n, q;
ll a[N];

struct sub1 {
    sub1() {
        ll x, f;
        while(q--) {
            cin >> x >> f;
            ll d = 1;
            for(int i = x + 1; i <= n; i++) {
                f -= (a[i] - a[i - 1]) * d;
                if(f < 0) 
                    break;
                d++;
            }
            cout << d << '\n';
        }
    }
};

struct sub2 {
    ll pre[N];
    sub2() {
        ll x, f;
        pre[0] = a[0] = 0;
        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + a[i];
        }
        while(q--) {
            cin >> x >> f;
            ll l = x, r = n, ans = x;

            while(l <= r) {
                ll mid = (l + r) / 2;
                // cout << mid << " " << (mid - x) * a[mid] - (pre[mid - 1] - pre[x - 1]) << '\n'; 
                if((mid - x) * a[mid] - (pre[mid - 1] - pre[x - 1]) <= f)
                    ans = mid, l = mid + 1;
                else 
                    r = mid - 1;
            }

            cout << ans - x + 1 << '\n';
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }

    cin >> n >> q;

    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    
    if(n * q <= 1e6)    
        new sub1;
    else
        new sub2;
}
