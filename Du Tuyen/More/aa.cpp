//problem "b"
//created in 23:43:04 - Sun 16/06/2024
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int int64_t

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    n *= 2;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> v;
    int c = 1;
    int mn = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < mn)
            c++;
        else {
            v.push_back({i - c, c});
            c = 1;
            mn = a[i];
        }
    }

    v.push_back({n - c, c});
    int dp[n / 2 + 1];
    memset(dp, -1, sizeof(dp));
    dp[0] = -2;
    for(int i = 0; i < v.size(); i++) {
        for(int j = n / 2; j >= v[i].second; j--) {
            if(dp[j - v[i].second] != -1 && dp[j] == -1)
                dp[j] = i;
        }
    }
    if(dp[n / 2] == -1)
        cout << -1 << endl;
    else {
        int ans[n / 2];
        set<int> s;
        int j = n / 2;
        int i = n - 1;
        int l = n / 2;
        while(j > 0) {
            int f = v[dp[j]].first, s = v[dp[j]].second;
            c = l - s;
            l -= s;
            i = f;
            while(s--) {
                ans[c++] = a[i++];
            }
            j -= v[dp[j]].second;
        }
        for(auto x: ans) {
            cout << x << " ";
            s.insert(x);
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            if(s.find(a[i]) == s.end())
                cout << a[i] << " ";
        }
        cout << endl;
    }
}