//problem "CSES2220"
//created in 14:52:26 - Tue 30/07/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int f[16][11][2];

int cal(int i, int bf, bool ok, vector<int> s) {
    if(i == s.size()) {
        return 1;
    }

    if(f[i][bf][ok] != -1)
        return f[i][bf][ok];
    
    f[i][bf][ok] = 0;

    for(int j = 0; j <= (ok ? 9 : s[i]); ++j) {
        if(j != bf) {
            f[i][bf][ok] += cal(i + 1, j, (ok | j < s[i]), s);
        }
    }

    return f[i][bf][ok];
}

int dem(int x) {
    if(x < 10) 
        return x + 1;
    vector<int> s;
    while(x > 0) {
        s.push_back(x % 10);
        x /= 10;
    }
    
    reverse(s.begin(), s.end());
    memset(f, -1, sizeof(f));

    return cal(0, 0, 0, s);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b;

    cin >> a >> b;

    cout << dem(b) - dem(a - 1);
}