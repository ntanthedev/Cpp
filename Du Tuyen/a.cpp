// template simple for codeforces by ntannn_
// created in 22:04:40 - Thu 01/02/2024
#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
vector<int> f, a;

int dp(int x) {
    if(f[x] != -1)
        return f[x];
    f[x] = 0;
    for(int y = (x % a[x]); y <= n; y += a[x]) {
        if(y == 0 || y == x || a[y] < a[x])
            continue;
        if(dp(y) == 0)
            f[x] = 1;
    }
    return f[x];
}

void solve() {
    cin >> n;
    a.resize(n + 1);
    f.resize(n + 1, -1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        dp(i);
    for(int i = 1; i <= n; i++) {
        if(f[i] == 1)
            cout << "A";
        else
            cout << "B";
    }
}

signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    // for(cin >> test_case;test_case--;cout << '\n')
    solve();
}