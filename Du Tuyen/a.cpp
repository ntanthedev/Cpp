//template simple for codeforces by ntannn_
//created in 22:00:53 - Thu 13/06/2024
#include <bits/stdc++.h>
#define int long long

using namespace std;

int f[20][2];
vector<int> a;

int dp(int i, bool ok) {
    if(i >= a.size())
        return 0;
    if(f[i][ok] != -1)
        return f[i][ok];
    f[i][ok] = 0;
    for(int j = 0; j <= (ok ? 9 : a[i]); j++)
        f[i][ok] += dp(i + 1, (ok || j < a[i])) + j;
    return f[i][ok];
}

int cal(int x) {

    a.clear(); 

    while(x > 0) {
        a.push_back(x % 10);
        x /= 10;
    }

    reverse(a.begin(), a.end());
    memset(f, -1, sizeof(f));

    return dp(0, 0);
}

void solve() {
    int x, y;
    cin >> x >> y;

    cout << cal(y) - cal(x - 1);
}

int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    a.reserve(16);
    for(cin >> test_case;test_case--;cout << '\n') 
        solve();
}
//98798