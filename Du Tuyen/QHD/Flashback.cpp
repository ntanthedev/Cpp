//problem "Flashback"
//created in 14:38:43 - Wed 15/05/2024

#include<bits/stdc++.h>

#define int int64_t
const int MOD = 1e9+7;

using namespace std;

int n, k;

void sub1() {
    vector<int> f(k + 2, 0);
    f[1] = n;
    for(int i = 1; i <= k; i++) {
        int res = 0;
        for(int j = i; j >= 1; j--)  
            res = (res + (j * f[j]) % MOD) % MOD,
            f[j + 1] = f[j];
        f[1] = res;
    }
    int ans = 0;
    for(int i = 1; i <= k + 1; i++) 
        ans += f[i] % MOD, ans %= MOD;
    cout << ans;
}

void sub2() {
    vector<int> f(2 * k + 2, 0);
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= 2 * k + 2; i++) 
        f[i] = f[i - 1] + f[i - 2],
        f[i] %= MOD;  
    
    cout << (f[k * 2 + 1] * n) % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> k;
    if(k <= 1e3) 
        sub1();    
    else 
        sub2();
}