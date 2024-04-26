//problem "a"
//created in 21:28:41 - Fri 26/04/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, x, y, ans = 0;
    cin >> n >> x;
    for(int i = 2; i <= n; i++) {
        cin >> y;
        ans += (y < x ? x - y : 0);
        x = y;
    }
    cout << ans;
}