//problem "a"
//created in 00:58:20 - Sun 11/08/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    int mmax = *max_element(a.begin() + 1, a.end());
    vector<vector<int>> s(mmax + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= mmax; j++)
            s[j][i] = s[j][i - 1];
        s[a[i]][i]++;
    }
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << s[k][r] - s[k][l - 1] << '\n';
    }
}