//problem "b"
//created in 00:11:56 - Wed 17/07/2024

#include<bits/stdc++.h> 
 
#define int int64_t 
const int MOD = 1e9 + 7;
 
using namespace std; 
 
int32_t main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
      
    int n, m;
    cin >> m >> n;
    vector<int> f(max(m + 1, n + 1));
    f[0] = 1,
    f[1] = 1;
    for(int i = 2; i <= max(m, n); ++i) 
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    cout << (2 * (f[n] + f[m] - 1) % MOD) % MOD;
} 