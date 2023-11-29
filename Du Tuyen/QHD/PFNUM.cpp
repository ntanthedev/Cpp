#include <bits/stdc++.h>
using namespace std;

long long a, b, dp[21][2][2][21][21];

long long solve(int i, int tight, bool ok, int pre1, int pre2, vector<int> digit) {
    if (i == digit.size()) return 1;
    if (dp[i][tight][ok][pre1][pre2] != -1) return dp[i][tight][ok][pre1][pre2];

    int upp_bound = tight == 0 ? 9 : digit[i];
    long long res = 0;
    for (int d = 0; d <= upp_bound; ++d) {
        int newtight = tight & (d == upp_bound);
        if((pre1 != d && pre2 != d)) {
        int tmp;
        if (!ok && d == 0) tmp = 10;
        else tmp = d;    

        res += solve(i + 1, newtight, ok || (d > 0), pre2, tmp, digit);
        }
    }

    return dp[i][tight][ok][pre1][pre2] = res;
}

long long F(long long x) {
    vector<int> digit;
    vector<int> saving;

    saving.resize(21, 0);

    while(x != 0) {
        digit.push_back(x % 10);
        x /= 10;
    }
    reverse(digit.begin(), digit.end());
    memset(dp, -1, sizeof dp); 

    return solve(0, 1, 0, -1, -1, digit);
}
void ReadInput() {
    cin >> a >> b;
}
void solve() {
    cout << F(b) - F(a - 1);
}
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("PFNUM.inp", "r", stdin);
    freopen("PFNUM.out", "w", stdout);
    ReadInput();
    solve();

} 