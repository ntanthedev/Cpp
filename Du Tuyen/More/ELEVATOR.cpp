#include<bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "ELEVATOR"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int m, n;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    int l = 1, r = 1e18, ans = 0;
    while(l <= r) { 
        int mid = (l + r) / 2;
        
    }
}