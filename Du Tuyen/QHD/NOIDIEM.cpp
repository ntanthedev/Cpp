//problem "NOIDIEM"
//created in 08:44:22 - Mon 13/05/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> s;
    int d = 0;
    for(auto i : s) {
        d += (i - '0');
    }
    cout << (d % 9 == 0 ? "Yes" : "No");
}