#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, s;
    cin >> n >> s;
    vector<int> a(n), dp(s + 1, 0);
    for(auto &i : a)
        cin >> i;
    
    function<int(int)> cal = [&](int x) {
        if(dp[x] != 0)
            return dp[x];
        
        // for(auto i : s) {
        //     if(i < s)

        // }
    };

    cout << cal(s);
}