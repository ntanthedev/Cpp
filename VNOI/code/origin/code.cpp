//problem "b"
//created in 09:16:09 - Sun 29/09/2024


#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define int int64_t
const int N = 1e6 + 5;

using namespace std;

int n, a[N];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    int ans = 0, res = 0;

    for(int i = 1; i <= n; i++) {
        if(a[i] < res + 1) 
            res = a[i];
        else
            res++;
        ans = max(ans, res);
    }

    cout << ans;
}