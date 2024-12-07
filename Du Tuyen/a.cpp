//problem "a"
//created in 16:03:08 - Fri 06/12/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        cout << i << " " << x << '\n';
    }
}