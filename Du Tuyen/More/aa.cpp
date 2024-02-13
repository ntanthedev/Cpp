//template simple for codeforces by ntannn_
//created in 23:10:45 - Mon 12/02/2024
#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int ans = 0;
}

signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case;test_case--;cout << '\n') 
        solve();
}