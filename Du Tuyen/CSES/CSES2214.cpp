//problem "CSES2214"
//created in 17:42:43 - Thu 16/10/2025

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k;

    cin >> n >> k;

    cout << k + 1 << " ";

    for(int i = 1; i <= n; i++) 
        if(i != k + 1) 
            cout << i << " ";
}