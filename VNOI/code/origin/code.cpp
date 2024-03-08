#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
vector <pair<int, int> > vt;
int Max, ans;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for (int s, t, i = 1; i <= n; i++) {
        cin >> s >> t;
        vt.push_back({s, t});
    }
    sort(vt.begin(), vt.end());
    Max = vt[0].second;
    for (auto [s, t] : vt) {
        if (s > Max)
            ans += s - Max - 1;
        Max = max(Max, t);
    }
    cout << ans;
}
