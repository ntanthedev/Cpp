//Written by: Jethro_
//----------------------
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;

long long m, n, a[N], b[N], sum[N], sum1[N], S = 0, E = 0, G = 0, cnt = 0, p[N * N];


void solve() {
    sum[0] = sum1[0] = 0;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        sum1[i] = sum1[i - 1] + b[i];
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; ++j) {
            p[++cnt] = sum[j] - sum[i - 1];
        }
    }
    sort(p + 1, p + cnt + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int t = upper_bound(p + 1, p + cnt + 1, sum1[j] - sum1[i - 1]) - p;
            int x = lower_bound(p + 1, p + cnt + 1, sum1[j] - sum1[i - 1]) - p;
            int t1 = upper_bound(p + 1, p + cnt + 1, sum1[j] - sum1[i - 1]) - lower_bound(p + 1, p + cnt + 1, sum1[j] - sum1[i - 1]);
            E += t1;
            G += (cnt - t + 1);           
            S += x - 1;



        }
    }
    cout << S <<' ' << E <<' ' << G << '\n';
}
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("SEQ2SC.inp", "r", stdin);
    // freopen("SEQ2SC.out", "w", stdout);
    solve();

}