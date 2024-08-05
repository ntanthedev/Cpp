//problem "a"
//created in 00:58:12 - Tue 06/08/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector<int> a = {1, 2, 3, 4, 5 ,6 };

    auto it = lower_bound(a.begin(), a.end(), 4);

    *it = 7;

    for(auto i : a) 
        cout << i << " ";
}