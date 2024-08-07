//problem "CSES2422"
//created in 21:02:21 - Wed 07/08/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int n, k;

bool check(int x) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt += x / i;
    }
    cout << cnt;
    return (cnt >= k);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    k = n * n / 2 + 1;
    int l = 1, r = n * n, ans = 0;

    check(3);
    exit(0);

    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else 
            l = mid + 1;
    }

    cout << ans;
}