//problem "c4"
//created in 18:23:52 - Sat 04/01/2025

#include<bits/stdc++.h>
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

#define int int64_t

using namespace std;

int n, k;

struct sub1 { //n <= 1e3
    sub1() {
        int ans = 0, p = 1;
        while(k < n) {
            p += k;
            if(p > n) 
                p %= n, k++;
            ans++;
            // cerr << p << " " << ans << " " << k << '\n';
        }
        cout << ans << '\n';
    }
};
// sub1: O(nlogn)

struct sub2 {

    sub2() {
        int p = 1, ans = 0;
        while(k < n) {
            int t = (n - p) / k;
            if(p + k * t <= n) 
                t++;
            p = (p + k * t) % n;
            ans += t;
            k++;
        }
        cout << ans << '\n';
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }

    cin >> n >> k;
    sub2();
    cerr << '\n' << "\x1b[31msub2: " << TIME << "\e[39m";
}
