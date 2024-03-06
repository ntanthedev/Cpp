//template simple for codeforces by ntannn_
//created in 21:59:48 - Tue 05/03/2024
#include <bits/stdc++.h>
#define int int64_t
#define se second
#define fi first

using namespace std;

void solve() {
    int n, mexarr = 0;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    for(auto &i : a) 
        cin >> i, m[i]++;
    for(auto i : m) {
        if(i.fi == mexarr)
            mexarr++;
        else 
            break;
    }
    if(mexarr > n / 2)
        return cout << -1, void();
    vector<pair<int, int> > ans;
    set<int> s;
    int d = 0;
    bool check = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < mexarr)
            s.insert(a[i]);
        if(s.size() == mexarr) {
            ans.push_back({1, i + 1});
            d = i;
            check = 1;
            break;
        }
    }
    s.clear();
    for(int i = d+1; i < n; i++) {
        if(a[i] < mexarr)
            s.insert(a[i]);
    }
    if(s.size() == mexarr) {
        ans.push_back({d + 2, n});
        cout << ans.size() << '\n';
        for(auto i : ans)
            cout << i.fi << " " << i.se << '\n';
    }
    else 
        cout << -1;
}

int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    #define task "aa"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case;
    for(cin >> test_case;test_case--;cout << '\n') 
        solve();
}
