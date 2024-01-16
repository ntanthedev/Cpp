#include <bits/stdc++.h>
using namespace std;

long long a, b, dp[20][2][20];

long long solve(int i, int tight, int prev, vector<int> digit, vector<int>&saving) {
    if (i == digit.size()) return 1;
    if (dp[i][tight][prev] != -1) return dp[i][tight][prev];

    int upp_bound = tight == 1 ? digit[i] : 9;
    long long res = 0;
    for (int d = 0; d <= upp_bound; ++d) {
        int newtight = tight & (d == upp_bound);
        saving[i] = d;
        if((d == saving[i - 2] && i > 1) || (d == saving[i - 1] && i > 0)) continue;
        res += solve(i + 1, newtight, d, digit, saving);
    }

    return dp[i][tight][prev] = res;
}

long long F(long long x) {
    vector<int> digit;
    vector<int> saving;

    saving.resize(18, 0);

    while(x != 0) {
        digit.push_back(x % 10);
        x /= 10;
    }
    reverse(digit.begin(), digit.end());
    memset(dp, -1, sizeof dp);

    return solve(0, 1, -1, digit, saving);
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
    // freopen("PFNUM.inp", "r", stdin);
    // freopen("PFNUM.out", "w", stdout);
    ReadInput();
    solve();

} 
// #include <bits/stdc++.h>
// #define all(x) x.begin(), x.end()

// using namespace std;

// typedef long long ll;

// ll a, b, f[21][2][2][21][21];

// ll solve(int i, int d, bool ok, int pre1, int pre2, vector<int> s) {
//     if(i == s.size())
//         return 1;
//     if(f[i][d][ok][pre1][pre2] != -1)
//         return f[i][d][ok][pre1][pre2];

//     int k = d == 0 ? 9 : s[i];
//     ll res = 0;
//     for(int d = 0; d <= k; ++d) {
//         int dd = d & (d == k);
//         if((pre1 != d && pre2 != d)) {
//             int t;
//             if(!ok && d == 0)
//                 t = 10;
//             else
//                 t = d;
//             res += solve(i + 1, dd, ok || (d > 0), pre2, t, s);
//         }
//     }

//     return f[i][d][ok][pre1][pre2] = res;
// }

// ll cal(ll x) {
//     vector<int> s;

//     while(x != 0) {
//         s.push_back(x % 10);
//         x /= 10;
//     }

//     reverse(all(s));
//     memset(f, -1, sizeof(f));

//     return solve(0, 1, 0, -1, -1, s);
// }
// void innit() {
//     cin >> a >> b;
// }
// void solve() {
//     cout << cal(b) - cal(a - 1);
// }
// int main() {
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);
//     freopen("PFNUM.inp", "r", stdin);
//     freopen("PFNUM.out", "w", stdout);
//     innit();
//     solve();
// }