#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;

ll a, b, f[21][2][2][21][21];

ll solve(int i, int d, bool ok, int pre1, int pre2, vector<int> s) {
    if(i == s.size())
        return 1;
    if(f[i][d][ok][pre1][pre2] != -1)
        return f[i][d][ok][pre1][pre2];

    int k = d == 0 ? 9 : s[i];
    ll res = 0;
    for(int d = 0; d <= k; ++d) {
        int dd = d & (d == k);
        if((pre1 != d && pre2 != d)) {
            int t;
            if(!ok && d == 0)
                t = 10;
            else
                t = d;
            res += solve(i + 1, dd, ok || (d > 0), pre2, t, s);
        }
    }

    return f[i][d][ok][pre1][pre2] = res;
}

ll cal(ll x) {
    vector<int> s;

    while(x != 0) {
        s.push_back(x % 10);
        x /= 10;
    }

    reverse(all(s));
    memset(f, -1, sizeof(f));

    return solve(0, 1, 0, -1, -1, s);
}
void innit() {
    cin >> a >> b;
}
void solve() {
    cout << cal(b) - cal(a - 1);
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("PFNUM.inp", "r", stdin);
    freopen("PFNUM.out", "w", stdout);
    innit();
    solve();
}