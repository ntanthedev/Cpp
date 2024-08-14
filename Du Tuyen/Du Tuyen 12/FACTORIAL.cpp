//problem "FACTORIAL"
//created in 07:43:55 - Wed 14/08/2024

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3e6 + 6;

ll n, Fs = 0;
string s;
ll F[10], cnt[10];
vector<vector<int>> c(10, vector<int>());

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "FACTORIAL"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> s;

    F[1] = 1;
    for(int i = 2; i <= 9; i++) {
        F[i] = F[i - 1] * i;
    }

    memset(cnt, 0, sizeof cnt);
    vector<string> ans(10);

    c[2] = {2};
    c[3] = {3};
    c[4] = {2, 2, 3};
    c[5] = {5};
    c[6] = {3, 5};
    c[7] = {7};
    c[8] = {2, 2, 2, 7};
    c[9] = {2, 3, 3, 7};

    s = ' ' + s;

    for(int i = 1; i <= n; i++) {
        int t = s[i] - '0';
        if(t < 2) 
            continue;
        for(auto j : c[t]) {
            ans[j].push_back(j + '0');
        }
    }    

    for(int i = 9; i >= 1; i--) {
        if(!ans[i].empty())
            cout << ans[i];
    }
}
