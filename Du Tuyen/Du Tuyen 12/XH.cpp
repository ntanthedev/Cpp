//problem "XH"
//created in 08:37:23 - Mon 22/07/2024

#include<bits/stdc++.h>

#define int int64_t
#define fi first 
#define se second

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> c(m);
    vector<tuple<int, int, int>> s(n);

    for(auto& [x, y, z] : s)
        cin >> x >> y >> z;
    for(auto& [r, h] : c)
        cin >> r >> h;

    if(n == 0) {
        
    }
}