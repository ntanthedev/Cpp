//problem "b"
//created in 17:00:18 - Tue 17/09/2024

#include<bits/stdc++.h>

#define int int64_t
const int N = 2e5 + 5;  

using namespace std;

int n, a[N], Q, s[N];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    

    #define task "b"
    // if(fopen(task ".inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    // }

    cin >> n >> Q; s[0] = 0;

    for(int i = 1; i <= n; i++) 
        cin >> a[i], s[i] = s[i - 1] + a[i];


    while(Q--) {
        int c, x, y;
        cin >> c >> x >> y;
        if(c & 1) {
            a[x] = y;
        }
        else {
            int ans = 0, res = 0;
            for(int i = x; i <= y; i++) {
                res += a[i];
                ans = max(ans, res);
            }
            cout << ans << '\n';
        }
    }
}