//problem "code"
//created in 16:13:07 - Sat 14/09/2024

#include<bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, cnt = 0;
    
    cin >> n;

    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(i & 1) 
                cnt++;
            int j = n / i;
            if(i != j && j & 1)
                cnt++;
        } 
    }

    cout << cnt;
}