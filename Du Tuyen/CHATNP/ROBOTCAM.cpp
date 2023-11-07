#include<bits/stdc++.h>
#define fi first 
#define se second
using namespace std;

signed main() {
    #define task "ROBOTCAM"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(auto i : a)
        cin >> i.fi >> i.se;
    
}