// template simple for codeforces by ntannn_
// created in 11:45:40 - Sun 14/07/2024
#include <bits/stdc++.h>
#define int int64_t

using namespace std;

bool check(int day, vector<int> a, int mmax) { 
    int odd = (day + 1) / 2, even = day / 2;
    for(auto i : a) {
        i = mmax - i; 
        int t = min(i >> 1, even);
        even -= t;
        i -= (t << 1);
        odd -= min(odd, i);
        if(!even && !odd)
            return false;
    } 
    cout << "check: " << day << " " << mmax << " " << odd << " " << even << '\n';
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& i: a)
        cin >> i;

    int mmax = *max_element(a.begin(), a.end()), ans = INT_MAX, res = 0;
    
    // check lan 1 
    int l = 0, r = INT_MAX;
    while(l <= r) { 
        int mid = (l + r) / 2;
        if(check(mid, a, mmax)) 
            ans = min(ans, mid), r = mid - 1;
        else 
            l = mid + 1;
    }

    l = 0, r = INT_MAX;
    while(l <= r) { 
        int mid = (l + r) / 2;
        if(check(mid, a, mmax + 1))
            ans = min(ans, mid), r = mid - 1;
        else 
            l = mid + 1;
    }

    cout << ans;
}

int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case; test_case--; cout << '\n')
        solve();
}