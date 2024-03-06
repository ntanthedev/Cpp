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
    vector<int> s(m.size() + 1, 0), b;
    b.push_back(0);
    // dem tg deu
    for(auto i : m) {
        b.emplace_back(i.fi);
        if(i.se >= 3) 
            ans += i.se * (i.se - 1) * (i.se - 2) / 6;
    }
    // int temp = ans;
    // cout << "deu: " << ans << '\n';
    // s[0] = b[0];
    for(int i = 1; i < b.size(); i++) {
        s[i] = s[i-1] + m[b[i]];
    }
    // s1[0] = 0;
    // for(int i = 1; i <= n; i++) {
    //     s1[i] = s1[i-1] + a[i-1];
    // }
    // dem tg can
    for(int i = 1; i < b.size(); i++) {
        if(m[b[i]] >= 2) {
            // cout << b[i] << '\n';
            ans += (lower_bound(b.begin() + 1, b.end(), 2 * b[i]) - b.begin() - 1);
            // cout << (lower_bound(b.begin() + 1, b.end(), 2 * b[i]) - b.begin() - 1) << '\n';    
        }
    }
    // cout << "can: " << ans - temp << '\n';
    // // dem tg thuong
    // cout << "b: "; for(int i = 1; i < b.size(); i++) cout << b[i] << " "; cout << '\n';
    for(int i = 1; i < b.size() - 1; i++) {
        for(int j = b.size() - 1; j >= i + 1; j++) {
            int t = lower_bound(b.begin() + 1 + j, b.end(), b[i] + b[j]) - b.begin() - 1;            
            
            ans += (t - j);
            // cout << i << " " << j << " " << t << " " << ans << '\n' ;
        }
    }
    
    // return cout << "check", 0;
    cout << ans ;
}