#include<bits/stdc++.h>

#define fi first 
#define se second 
#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define task "TRIANGLES"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    vector<int> b;
    b.push_back(0);
    for(auto i : m) {
        if(i.se >= 3)
            ans++;
        b.push_back(i.fi);
    }

    for(int i = 1; i < b.size(); i++) {
        if(m[b[i]] >= 2) {
            auto t = lower_bound(b.begin() + 1, b.end(), 2*b[i]) - b.begin() - 1;
            if(b[t] >= i)
                t--;
            ans += t;
        }
    }
    
    for(int i = 1; i < b.size() - 1; i++) {
        for(int j = b.size() - 1; j >= i + 1; j++) {
            int t = lower_bound(b.begin() + 1, b.begin() + 1 + j, b[i] + b[j]) - b.begin() - 1;                        
            ans += (t - j);    
        }
    }
    cout << ans ;
}