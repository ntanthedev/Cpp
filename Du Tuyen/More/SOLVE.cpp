//problem "SOLVE"
//created in 09:50:07 - Sun 12/05/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int cal_digit(int x) {
    int res = 0;
    while(x != 0) {
        res = (res << 3) + (res << 1) + x % 10;
        x /= 10;
    }
    return x;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;

    int l = 1, r = 1e10, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(mid * mid + cal_digit(mid)*mid - n >= 0) 
            cout << 1 << " " << ans << " " << l << " " << r << '\n',ans = mid, r = mid - 1;
        else 
            cout << 2 << " " << ans << " " << l << " " << r << '\n',l = mid + 1;
    }

    cout << (ans == -1) || (ans * ans + cal_digit(ans) * ans - n != 0) ? -1 : ans;
}