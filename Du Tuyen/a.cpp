//problem "a"
//created in 07:53:23 - Thu 15/08/2024

#include<bits/stdc++.h>

using namespace std;

const int N = 105;
const int MOD = 1e9 + 7;
typedef long long ll;

ll n, res = 0, a[N];
bool L[1000009];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "pa"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        res += a[i];
    }
    
    L[0] = 1;
    for(int i = 1; i <= n; i++) 
        for(int j = res; j >= a[i]; j--) 
            if(L[j - a[i]])
                L[j] = 1;
    
    vector<int> p;
    for(int i = 0; i <= res; i++) {
        if(L[i])
            p.push_back(i);
    }

    ll ans = 0;
    for(int i = 0; i < p.size(); i++) {
        ll t = res;
        if(i > 0) 
            t -= p[i - 1];
        t += t;
        t -= lower_bound(p.begin(), p.end(), res - p[i]) - p.begin() + 2;
        ans += t;
    }

    cout << ans;
}

/*
dp[i][j][k] = dp[i - 1][j + 1 -> n][k - 1]
*/