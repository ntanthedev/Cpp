#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
long long dp[100005][19][2][2][4][2];

string st;

long long cal(int i, int lo, int rem, bool ar1, bool ar2, int ar0, bool ok) {
    if (i == 0) return !rem;
    if (lo && dp[i][rem][ar1][ar2][ar0][ok] != -1) return dp[i][rem][ar1][ar2][ar0][ok];

    long long res = 0, limit = (lo ? 9 : (st[st.size() - i] - '0'));
    for (int d = 0; d <= limit; ++d) {

        int newa, newb, newc;
        newa = ar1 || (d % 3 == 1);
        newb = ar2 || (d % 3 == 2);
        newc = ar0 + (d % 3 == 0 && (!ok || d != 0));

        if (newa && newb || newc >= 2) continue;

        res += cal(i - 1, lo || (d < limit), (rem * 10 + d) % 19, newa, newb, newc, ok & (d == 0));
        res %= mod;
    }

    return (lo ? dp[i][rem][ar1][ar2][ar0][ok] = res : res);
}
//1 2
//3

long long cc() {

    vector<int> mark(3, 0); long long s = 0;
    for (int i = 0; i < st.size(); ++i) {
        mark[1] += ((st[i] - '0') % 3 == 1);
        mark[2] += ((st[i] - '0') % 3 == 2);
        mark[0] += ((st[i] - '0') % 3 == 0);
        s = (s * 10 + (st[i] - '0')) % 19;
        if (mark[1] && mark[2] || mark[0] >= 2) return 0;
    }

    return !s;
}
void solve() {

    string l, r; cin >> l >> r;

    st = l;
    long long a = cal(l.size(), 0, 0, 0, 0, 0, 1), more = cc();
    st = r;
    long long b = cal(r.size(), 0, 0, 0, 0, 0, 1);
    cout << (b - a + more + mod) % mod << '\n';

}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    #define task "b"
        freopen("test.inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    // }
    memset(dp, -1, sizeof dp);
    int t; cin >> t;
    while (t--) solve();
}
