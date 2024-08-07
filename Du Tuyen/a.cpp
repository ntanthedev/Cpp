//problem "a"
//created in 10:23:49 - Tue 06/08/2024

#include<bits/stdc++.h>

#define int int64_t
const int MOD = 1e9 + 7;
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) 
            cout << i * j << " ";
        cout << '\n';
    }

    vector<int> a;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            a.push_back(i * j);
    sort(a.begin(), a.end());
    for(auto i : a) 
        cout << i << " ";
}