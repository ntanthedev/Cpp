//problem "a"
//created in 20:03:53 - Sun 15/09/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

vector<int> s;
int f[20][2][2];

int cal(int i, bool ok, int r) {
    if(i == s.size()) 
        return r;
    
    if(f[i][ok][r] + 1) 
        return f[i][ok][r];

    f[i][ok][r] = 0;

    for(int j = 0; j <= (ok ? 9 : s[i]); j++) {
        if(i == s.size() - 1 && j % 2 == 0)
            continue;
        f[i][ok][r] += cal(i + 1, ok || (j < s[i]), (r + j) % 2);
    }

    return f[i][ok][r];
}

int pre(int x) {
    if(x < 1)
        return 0;
    s.clear();

    while(x) {
        s.push_back(x % 10);
        x /= 10;
    }

    reverse(s.begin(), s.end());
    memset(f, -1, sizeof(f));

    return cal(0, 0, 0) ;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;    

    // cout << pre(n); exit(0);

    int l = 0, r = 2e16, ans = 0;

    while(l <= r) {
        int mid = (l + r) / 2;
        if(pre(mid) >= n) {
            ans = mid;
            r = mid - 1;
        }
        else 
    l = mid + 1;
    }

    cout << ans;
}