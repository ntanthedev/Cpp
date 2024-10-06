//problem "a"
//created in 22:12:41 - Wed 02/10/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // #define task "test"
    // if(fopen(task ".inp", "r")) {
    //     freopen(task ".inp", "r", stdin);
    //     freopen("b.out", "w", stdout);
    // }

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i: a)
        cin >> i;

    int ans = 0;
    int bit = 0;                   
    int cnt[4] = {0};  
    cnt[0] = 1;        

    for(auto num: a) {
        if(num % 2 == 0) 
            bit ^= 1;
        else 
            bit ^= 2;
        
        int res = bit ^ 1;

        ans += cnt[res];

        cnt[bit]++;
    }

    cout << ans;
}
